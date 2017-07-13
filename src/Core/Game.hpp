#pragma once
#include "../Graphics/Shader.hpp"
#include "../Graphics/Renderer.hpp"
#include "../Graphics/Model.hpp"
#include "../Graphics/Camera.hpp"

/* class Input; */

class Game
{
public:
  void load();
  void update(double dt);
  void draw();
  void quit();

private:
  Shader mShader;
  Renderer mRenderer;
  Model mModel;
  Camera mCamera;

};
