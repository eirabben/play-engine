#pragma once
#include <glm/glm.hpp>
#include "Mesh.hpp"
#include "Material.hpp"

class Model
{
public:
  void init(Mesh mesh, Material material);

  Mesh& getMesh();
  Material& getMaterial();
  glm::mat4 getModelMatrix();

private:
  Mesh mMesh;
  Material mMaterial;
  glm::mat4 mModelMatrix;

};
