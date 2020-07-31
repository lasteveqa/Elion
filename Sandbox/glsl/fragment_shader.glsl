#version 430 core


uniform sampler2D u_Texture;

in vec2 v_TexCoord;
in vec4 v_Color;
in vec2 AnimTexturePosition;

out vec4 color;
out vec4 outColor;


void main()
{




vec4 TexColor = texture(u_Texture , vec2(v_TexCoord.x / 12  , v_TexCoord.y / 8) + AnimTexturePosition);
if(TexColor.a < 0.1)
       discard;
outColor = TexColor;

}