#include "Game.hpp"
#include <iostream>
#include <vector>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "../Graphics/MeshLoader.hpp"
#include "../Graphics/TextureLoader.hpp"
#include "../Graphics/Mesh.hpp"
#include "../Graphics/Texture.hpp"

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

  MeshLoader meshLoader;
  Mesh mesh = meshLoader.loadMesh(vertices, indices);

  TextureLoader textureLoader;
  Texture texture = textureLoader.loadTexture("res/Textures/container.jpg");

  mModel.init(mesh, texture);
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
