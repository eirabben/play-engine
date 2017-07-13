#pragma once
#include <glm/glm.hpp>
#include "Mesh.hpp"
#include "Texture.hpp"

class Model
{
public:
  void init(Mesh mesh, Texture texture);

  Mesh& getMesh();
  Texture& getTexture();
  glm::mat4 getModelMatrix();

private:
  Mesh mMesh;
  Texture mTexture;
  glm::mat4 mModelMatrix;

};
