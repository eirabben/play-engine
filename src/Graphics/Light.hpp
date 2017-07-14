#pragma once
#include <glm/glm.hpp>

class Light
{
public:
  void init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);

  glm::vec3 getAmbient();
  glm::vec3 getDiffuse();
  glm::vec3 getSpecular();

protected:
  glm::vec3 mAmbient;
  glm::vec3 mDiffuse;
  glm::vec3 mSpecular;

};

class DirectionalLight : public Light
{
public:
  void init(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  glm::vec3 getDirection();

private:
  glm::vec3 mDirection;
};

class PointLight : public Light
{
public:
  void init(glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float constant, float linear, float quadratic);
  glm::vec3 getPosition();
  float getConstant();
  float getLinear();
  float getQuadratic();

private:
  glm::vec3 mPosition;
  float mConstant;
  float mLinear;
  float mQuadratic;

};

class SpotLight : public Light
{
public:
  void init(glm::vec3 position, glm::vec3 direction, float cutOff, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  glm::vec3 getPosition();
  glm::vec3 getDirection();
  float getCutOff();

private:
  glm::vec3 mPosition;
  glm::vec3 mDirection;
  float mCutOff;
};
