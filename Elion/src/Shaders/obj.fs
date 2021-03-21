#version 430 core
out vec4 FragColor;

in vec2 TexCoords;

uniform vec4 UniformColor;

uniform sampler2D texture_diffuse;

void main()
{    
    //FragColor = texture(texture_diffuse, TexCoords);
   FragColor = UniformColor;
}