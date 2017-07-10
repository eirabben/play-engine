#include "Model.hpp"

void Model::init(Mesh mesh, Texture texture)
{
  mMesh = mesh;
  mTexture = texture;
}

Mesh& Model::getMesh()
{
  return mMesh;
}

Texture& Model::getTexture()
{
  return mTexture;
}
