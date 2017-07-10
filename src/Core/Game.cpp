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
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
  };

  std::vector<unsigned int> indices = {
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
  };

  ModelLoader modelLoader;
  mModel = modelLoader.loadModel(vertices, indices);

  TextureLoader textureLoader;
  texture = textureLoader.loadTexture("res/Textures/container.jpg");
}

void Game::update(double dt)
{
  
}

void Game::draw()
{
  mShader.use();

  mRenderer.render(mModel);
}

void Game::quit()
{
  
}

void Game::handleInput()
{

}