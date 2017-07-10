#pragma once
#include "../Graphics/Shader.hpp"
#include "../Graphics/Renderer.hpp"
#include "../Graphics/Model.hpp"
#include "../Graphics/Texture.hpp"

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
  Renderer mRenderer;
  Model mModel;
  Texture mTexture;

};
