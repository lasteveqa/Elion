#version 430 core
layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec2 a_Texture;
layout (location = 2) in vec3 a_Normal;

out vec2 TexCoords;

uniform mat4 transform;
uniform mat4 cameraView;
uniform mat4 projection;

void main()
{
    TexCoords = a_Texture;
    gl_Position = projection * cameraView * transform * vec4(a_Position, 1.0);
}