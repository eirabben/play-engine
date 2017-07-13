#pragma once
#include "Model.hpp"
#include "Camera.hpp"
#include "Shader.hpp"

class Renderer
{
public:
  void render(Camera& camera, Shader& shader, Model& model);

private:

};
