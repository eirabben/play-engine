#pragma once
#include "Input.hpp"
#include "../Graphics/Shader.hpp"
#include "../Graphics/Renderer.hpp"
#include "../Graphics/Model.hpp"
#include "../Graphics/Camera.hpp"
#include "../Graphics/Light.hpp"

class Game
{
public:
  void load();
  void update(double dt);
  void draw();
  void quit();

  void handleInput(int key, int scancode, int action, int mods);
  void handleMouse(double x, double y);
  void handleScroll(double offsetX, double offsetY);

private:
  Input mInput;
  Shader mShader;
  Camera mCamera;
  Renderer mRenderer;

  Model mModel;
  DirectionalLight mDirLight;
  PointLight mPointLight;

};
