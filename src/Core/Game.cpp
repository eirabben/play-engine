#include "Game.hpp"
#include <iostream>
#include <vector>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../Graphics/MeshLoader.hpp"
#include "../Graphics/TextureLoader.hpp"
#include "../Graphics/Mesh.hpp"
#include "../Graphics/Material.hpp"
#include "../Graphics/Texture.hpp"

void Game::load()
{
  mShader.init("res/Shaders/color.vert", "res/Shaders/color.frag");

  std::vector<float> vertices = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
  };

  mCamera.init(glm::vec3(0.0f, 0.0f, 3.0f));

  MeshLoader meshLoader;
  Mesh mesh = meshLoader.loadMesh(vertices);

  TextureLoader textureLoader;
  Texture diffuse = textureLoader.loadTexture("res/Textures/container2.png");
  Texture specular = textureLoader.loadTexture("res/Textures/container2_specular.png");

  Material material;
  material.init(diffuse, specular, 64.0f);

  mModel.init(mesh, material);

  mDirLight.init(glm::vec3(-0.2f, -1.0f, -0.3f), glm::vec3(0.05f, 0.05f, 0.05f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.5f, 0.5f, 0.5f));
  mPointLight.init(glm::vec3(0.7f,  0.2f,  2.0f), glm::vec3(0.05f, 0.05f, 0.05f), glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f, 0.09f, 0.032f);

  mInput.addAction("MOVE_FORWARD", [this](double dt) {
    mCamera.updatePosition(CameraMovement::FORWARD, dt);
  });
  mInput.addAction("MOVE_BACKWARD", [this](double dt) {
    mCamera.updatePosition(CameraMovement::BACKWARD, dt);
  });
  mInput.addAction("MOVE_LEFT", [this](double dt) {
    mCamera.updatePosition(CameraMovement::LEFT, dt);
  });
  mInput.addAction("MOVE_RIGHT", [this](double dt) {
    mCamera.updatePosition(CameraMovement::RIGHT, dt);
  });
  mInput.addAction("MOVE_UP", [this](double dt) {
    mCamera.updatePosition(CameraMovement::UP, dt);
  });
  mInput.addAction("MOVE_DOWN", [this](double dt) {
    mCamera.updatePosition(CameraMovement::DOWN, dt);
  });

  mInput.bindKeyDown(GLFW_KEY_W, "MOVE_FORWARD");
  mInput.bindKeyDown(GLFW_KEY_S, "MOVE_BACKWARD");
  mInput.bindKeyDown(GLFW_KEY_A, "MOVE_LEFT");
  mInput.bindKeyDown(GLFW_KEY_D, "MOVE_RIGHT");
  mInput.bindKeyDown(GLFW_KEY_LEFT_SHIFT, "MOVE_UP");
  mInput.bindKeyDown(GLFW_KEY_LEFT_CONTROL, "MOVE_DOWN");
  mInput.bindMouseMove([this](double x, double y, double offsetX, double offsetY) {
      mCamera.updateViewDirection(offsetX, offsetY);
  });
}

void Game::update(double dt)
{
  mInput.update(dt);
}

void Game::draw()
{
  mRenderer.render(mCamera, mShader, mModel, mDirLight, mPointLight);
}

void Game::quit()
{
  
}

void Game::handleInput(int key, int scancode, int action, int mods)
{
  if (action == GLFW_PRESS)
  {
    mInput.keyPressed(key);
  }

  if (action == GLFW_RELEASE)
  {
    mInput.keyReleased(key);
  }
}

void Game::handleMouse(double x, double y)
{
  mInput.mouseMoved(x, y);
}

void Game::handleScroll(double offsetX, double offsetY)
{
  mInput.wheelMoved(offsetX, offsetY);
}

