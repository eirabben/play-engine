#include "Game.hpp"
#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "../Graphics/ModelLoader.hpp"
#include "../Graphics/TextureLoader.hpp"
#include <vector>

void Game::load()
{
  mShader.init("res/Shaders/color.vert", "res/Shaders/color.frag");

  std::vector<float> vertices = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
  };

  std::vector<unsigned int> indices = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
  };

  ModelLoader modelLoader;
  mModel = modelLoader.loadModel(vertices, indices);

  TextureLoader textureLoader;
  mTexture = textureLoader.loadTexture("res/Textures/container.jpg");
}

void Game::update(double dt)
{
  
}

void Game::draw()
{
  mShader.use();

  glBindTexture(GL_TEXTURE_2D, mTexture.getId());

  mRenderer.render(mModel);
}

void Game::quit()
{
  
}

void Game::handleInput()
{

}
