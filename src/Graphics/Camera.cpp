#include "Camera.hpp"
#include "glm/gtc/matrix_transform.hpp"

void Camera::init(glm::vec3 position)
{
  mPosition = position;
  updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
  return glm::lookAt(mPosition, mPosition + mFront, mUp);
}

float Camera::getZoom()
{
  return mZoom;
}

void Camera::updatePosition(CameraMovement direction, double deltaTime)
{
  float velocity = mMovementSpeed * deltaTime;

  if (direction == FORWARD)
  {
    mPosition += mFront * velocity;
  }
  if (direction == BACKWARD)
  {
    mPosition -= mFront * velocity;
  }
  if (direction == LEFT)
  {
    mPosition -= mRight * velocity;
  }
  if (direction == RIGHT)
  {
    mPosition += mRight * velocity;
  }
}

void Camera::updateViewDirection(float xOffset, float yOffset, bool constrainPitch)
{
  xOffset *= mMouseSensitivity;
  yOffset *= mMouseSensitivity;

  mYaw += xOffset;
  mPitch += yOffset;

  if (constrainPitch)
  {
    if (mPitch > 89.0f)
    {
      mPitch = 89.0f;
    }
    if (mPitch < -89.0f)
    {
      mPitch = -89.0f;
    }
  }

  updateCameraVectors();
}

void Camera::updateZoom(float yOffset)
{
  if (mZoom >= 1.0f && mZoom <= 45.0f)
  {
    mZoom -= yOffset;
  }
  if (mZoom <= 1.0f)
  {
    mZoom = 1.0f;
  }
  if (mZoom >= 45.0f)
  {
    mZoom = 45.0f;
  }
}

void Camera::updateCameraVectors()
{
  glm::vec3 front;
  front.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
  front.y = sin(glm::radians(mPitch));
  front.z = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
  mFront = glm::normalize(front);

  mRight = glm::normalize(glm::cross(mFront, mWorldUp));
  mUp = glm::normalize(glm::cross(mRight, mFront));
}
