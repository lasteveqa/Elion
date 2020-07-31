#version 430 core




layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 TexCoord;

uniform int AnimationNumber;

out vec2 AnimTexturePosition;

uniform mat4 transform;

out vec2 v_TexCoord;


out vec4 v_Color;
void main()
{


switch(AnimationNumber)
{
case 0:
  AnimTexturePosition = vec2(0.086f, 0.0f);
  break;

case 1:
  AnimTexturePosition = vec2(0.086f, 0.128f);
  break;

case 2:
 AnimTexturePosition = vec2(0.086f, 0.252f);
 break;
case 3:
 AnimTexturePosition = vec2(0.086f, 0.378f);
 break;
}
v_Color = aColor;
 gl_Position = transform * vec4(aPos, 1.0f);
 v_TexCoord = TexCoord;

}