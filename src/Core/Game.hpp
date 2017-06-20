#pragma once
#include "../Graphics/Shader.hpp"

class Game
{
public:
  void load();
  void update(double dt);
  void draw();
  void quit();

  void handleInput();

private:
  Shader mShader;
  unsigned int vao;
  unsigned int vbo;

};