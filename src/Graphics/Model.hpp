#pragma once
#include "Mesh.hpp"
#include "Texture.hpp"

class Model
{
public:
  void init(Mesh mesh, Texture texture);

  Mesh& getMesh();
  Texture& getTexture();

private:
  Mesh mMesh;
  Texture mTexture;

};
