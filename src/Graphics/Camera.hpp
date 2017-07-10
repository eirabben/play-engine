#pragma once
#include "glm/glm.hpp"

enum CameraMovement
{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

class Camera
{
public:
  void init(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));

  glm::mat4 getViewMatrix();

  void updatePosition(CameraMovement direction, double deltaTime);
  void updateViewDirection(float xOffset, float yOffset, bool constrainPitch);
  void updateZoom(float yOffset);


private:
  glm::vec3 mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 mFront = glm::vec3(0.0f, 0.0f, -1.0f);
  glm::vec3 mUp = glm::vec3(0.0f, 1.0f, 0.0f);
  glm::vec3 mRight;
  glm::vec3 mWorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

  float mYaw = -90.0f;
  float mPitch = 0.0f;

  float mMovementSpeed = 2.5f;
  float mMouseSensitivity = 0.1f;
  float mZoom = 45.0f;

  void updateCameraVectors();
};
