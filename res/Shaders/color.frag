#version 330 core

struct Material {
  sampler2D diffuse;
  sampler2D specular;
  float shininess;
};

struct DirLight {
  vec3 direction;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

struct PointLight {
  vec3 position;

  float constant;
  float linear;
  float quadratic;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};
#define NR_POINT_LIGHTS 1

out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;

uniform Material material;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform vec3 viewPosition;

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 calcPointLight(PointLight light, vec3 normal, vec3 fPos, vec3 viewDir);

void main()
{
  // Properties
  vec3 norm = normalize(normal);
  vec3 viewDir = normalize(viewPosition - fragPos);

  // Directional lighting
  vec3 result = calcDirLight(dirLight, norm, viewDir);

  // Point lights
  for (int i = 0; i < NR_POINT_LIGHTS; i++)
  {
    result += calcPointLight(pointLights[i], norm, fragPos, viewDir);
  }

  FragColor = vec4(result, 1.0);

} 

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
  vec3 lightDir = normalize(-light.direction);

  // Diffuse shading
  float diff = max(dot(normal, lightDir), 0.0);

  // Specular shading
  vec3 reflectDir = reflect(-lightDir, normal);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

  vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoords));
  vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoords));
  vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));

  return (ambient + diffuse + specular);
}

vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPosition, vec3 viewDir)
{
  vec3 lightDir = normalize(light.position - fragPosition);
  // diffuse shading
  float diff = max(dot(normal, lightDir), 0.0);
  // specular shading
  vec3 reflectDir = reflect(-lightDir, normal);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
  // attenuation
  float distance = length(light.position - fragPosition);
  float attenuation = 1.0 / (light.constant + light.linear * distance + 
           light.quadratic * (distance * distance));    
  // combine results
  vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, texCoords));
  vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, texCoords));
  vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));
  ambient  *= attenuation;
  diffuse  *= attenuation;
  specular *= attenuation;
  return (ambient + diffuse + specular);
}
