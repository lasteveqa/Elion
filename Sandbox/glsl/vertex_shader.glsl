#version 430 core




layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
mat4 MVP = projection * view * model;
 gl_Position = MVP * vec4(aPos , 0.5f);
}