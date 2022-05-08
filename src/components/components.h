#pragma once
#include <vultr.h>

VCOMPONENT_BEGIN(TestComponent)
VCOMPONENT_FIELD(u32, test_u32, 0)
VCOMPONENT_FIELD(f32, test_f32, 0)
VCOMPONENT_END()
VCOMPONENT_BEGIN(CharacterController)
VCOMPONENT_FIELD(f32, movement_speed, 10)
VCOMPONENT_FIELD(f32, sensitivity, 90)
VCOMPONENT_END()