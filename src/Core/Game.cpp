#include "Game.hpp"
#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "../Graphics/Model.hpp"
#include "../Graphics/ModelLoader.hpp"
#include <vector>

void Game::load()
{
  mShader.compileShaders("res/Shaders/color.vert", "res/Shaders/color.frag");

  std::vector<float> vertices = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  ModelLoader loader;
  loader.loadModel(model, vertices);

  // glGenVertexArrays(1, &vao);
  // glGenBuffers(1, &vbo);

  // glBindVertexArray(vao);

  // glBindBuffer(GL_ARRAY_BUFFER, vbo);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);

  // glBindBuffer(GL_ARRAY_BUFFER, 0);

  // glBindVertexArray(0);
}

void Game::update(double dt)
{
  
}

void Game::draw()
{

  mShader.use();

  mRenderer.render(model);

  // glBindVertexArray(vao);
  // glDrawArrays(GL_TRIANGLES, 0, 3);

  mShader.unuse();
}

void Game::quit()
{
  
}

void Game::handleInput()
{

}
