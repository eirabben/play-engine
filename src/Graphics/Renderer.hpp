#pragma once
#include "Model.hpp"
#include "Camera.hpp"
#include "Shader.hpp"
#include "Light.hpp"

class Renderer
{
public:
  void render(Camera& camera, Shader& shader, Model& model, DirectionalLight& dirLight, PointLight& pointLight);

private:

};
