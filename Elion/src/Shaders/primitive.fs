#version 430 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;    
    vec3 vambient;
    vec3 vdiffuse;
    vec3 vspecular;
    float shininess;
}; 

struct Light {
    vec3 position;  
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	
    float constant;
    float linear;
    float quadratic;
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;
uniform vec4 UniformColor;

void main()
{
    // ambient
    vec3 ambient = light.ambient * material.vambient;
    
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.vdiffuse) ;  
    
    // specular
   // vec3 viewDir = normalize(viewPos - FragPos);
   // vec3 reflectDir = reflect(-lightDir, norm);  
   // float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
   // vec3 specular = light.specular * (spec * material.vspecular);  
   
        
    vec3 result = ambient + diffuse;
    FragColor = vec4(result, 1.0f);
} 