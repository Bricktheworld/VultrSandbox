#include <vultr.h>
#include <vultr_input.h>
#include <core/components/components.h>
#include "components/components.h"

using namespace Vultr;
struct GameplayState
{
    Platform::CallbackHandle cursor_lock_handle{};
};

void use_game_memory(void *m) { g_game_memory = static_cast<GameMemory *>(m); }
void vultr_register_components()
{
    world()->component_manager.register_component<TestComponent>();
    world()->component_manager.register_component<CharacterController>();
}

static void on_key_press(void *void_state, Input::Key key, Input::Action action, Input::Key modifiers)
{
    auto *state = static_cast<GameplayState *>(void_state);
    if (action == Input::ACTION_PRESS)
    {
        if (key == Input::KEY_ESCAPE)
        {
            Input::unlock_mouse();
        }
    }
}

void *vultr_init(void)
{
    auto *state = v_alloc<GameplayState>();

    state->cursor_lock_handle = Platform::register_key_callback(engine()->window, state, on_key_press);

    // Initialize random.
    srand((u32)time(nullptr));

    return state;
}

void vultr_update(void *void_state, f64 dt)
{
    auto *state = static_cast<GameplayState *>(void_state);

    if (Input::mouse_down(Input::MOUSE_LEFT))
    {
        Input::lock_mouse();
    }

    if (Input::is_mouse_locked())
    {
        for (auto [entity, character_controller, transform] : get_entities<CharacterController, Transform>())
        {
            f32 delta_movement = character_controller->movement_speed * dt;
            if (Input::key_down(Input::KEY_W))
            {
                transform->position += forward(*transform) * delta_movement;
            }
            if (Input::key_down(Input::KEY_S))
            {
                transform->position -= forward(*transform) * delta_movement;
            }
            if (Input::key_down(Input::KEY_D))
            {
                transform->position += right(*transform) * delta_movement;
            }
            if (Input::key_down(Input::KEY_A))
            {
                transform->position -= right(*transform) * delta_movement;
            }

            auto mouse_delta = Input::mouse_delta();

            Quat rotation_horiz = glm::angleAxis(f32(character_controller->sensitivity * dt * -mouse_delta.x), Vec3(0, 1, 0));
            Quat rotation_vert  = glm::angleAxis(f32(character_controller->sensitivity * dt * -mouse_delta.y), right(*transform));
            transform->rotation = rotation_horiz * transform->rotation;
        }
    }
}

void vultr_destroy(void *void_state)
{
    auto *state = static_cast<GameplayState *>(void_state);
    v_free(state);
}
