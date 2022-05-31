#[UNIFORMS]

layout (set = 1, binding = 0) uniform Skybox {
    vec4 unused;
} u_Skybox;
layout (set = 1, binding = 1) uniform sampler2D u_Albedo;

#[VERTEX]
layout (location = 0) out vec2 f_UV;

void main()
{
    f_UV = vec2(v_Position);
    gl_Position = u_Camera.view_proj * vec4(v_Position, 1.0f);
}

#[FRAGMENT]

layout (location = 0) out vec4 color;

layout (location = 0) in vec2 f_UV;

void main()
{
    color = texture(u_Albedo, f_UV);
}
