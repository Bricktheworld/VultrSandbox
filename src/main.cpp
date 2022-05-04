#include <vultr.h>
#include <core/components/components.h>

using namespace Vultr;
struct GameplayState
{
    Entity rock   = INVALID_ENTITY;
    Entity teapot = INVALID_ENTITY;
    Entity sword  = INVALID_ENTITY;
    Entity light  = INVALID_ENTITY;
    f64 dx        = 10;
};

void use_game_memory(void *m) { g_game_memory = static_cast<GameMemory *>(m); }
void *vultr_init(void)
{
    auto *state = v_alloc<GameplayState>();

    state->rock   = create_entity("Rock", Mesh{.source = Resource<Platform::Mesh *>("meshes/rock.fbx")}, Transform{.scale = Vec3(0.01)}, Material{.source = Resource<Platform::Material *>("materials/rock.mat")});
    state->sword  = create_entity("Sword", Mesh{.source = Resource<Platform::Mesh *>("meshes/sword.fbx")}, Transform{.scale = Vec3(0.038)}, Material{.source = Resource<Platform::Material *>("materials/sword.mat")});
    state->teapot = create_entity("Teapot", Mesh{.source = Resource<Platform::Mesh *>("meshes/teapot.fbx")}, Transform{}, Material{.source = Resource<Platform::Material *>("materials/teapot.mat")});
    state->light  = create_entity("Light", Transform{}, DirectionalLight{.intensity = 20});
    return state;
}
void vultr_update(void *void_state, f64 dt)
{
    auto *state = static_cast<GameplayState *>(void_state);
    //    auto &transform = get_component<Transform>(state->rock);
    //    if (transform.position.x > 20 || transform.position.x < -20)
    //    {
    //        state->dx *= -1;
    //    }
    //    transform.position.x += state->dx * dt;
}

void vultr_destroy(void *void_state)
{
    auto *state = static_cast<GameplayState *>(void_state);
    //    destroy_entity(state->sword);
    //    destroy_entity(state->teapot);
    //    destroy_entity(state->rock);
}
