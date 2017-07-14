#include "Light.hpp"

void Light::init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
  mAmbient = ambient;
  mDiffuse = diffuse;
  mSpecular = specular;
}

glm::vec3 Light::getAmbient()
{
  return mAmbient;
}

glm::vec3 Light::getDiffuse()
{
  return mDiffuse;
}

glm::vec3 Light::getSpecular()
{
  return mSpecular;
}

void DirectionalLight::init(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
  mDirection = direction;
  Light::init(ambient, diffuse, specular);
}

glm::vec3 DirectionalLight::getDirection()
{
  return mDirection;
}

void PointLight::init(glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float constant, float linear, float quadratic)
{
  mPosition = position;
  mConstant = constant;
  mLinear = linear;
  mQuadratic = quadratic;
  Light::init(ambient, diffuse, specular);
}

glm::vec3 PointLight::getPosition()
{
  return mPosition;
}

float PointLight::getConstant()
{
  return mConstant;
}

float PointLight::getLinear()
{
  return mLinear;
}

float PointLight::getQuadratic()
{
  return mQuadratic;
}

void SpotLight::init(glm::vec3 position, glm::vec3 direction, float cutOff, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
  mPosition = position;
  mDirection = direction;
  mCutOff = cutOff;
  Light::init(ambient, diffuse, specular);
}

glm::vec3 SpotLight::getPosition()
{
  return mPosition;
}

glm::vec3 SpotLight::getDirection()
{
  return mDirection;
}

float SpotLight::getCutOff()
{
  return mCutOff;
}
