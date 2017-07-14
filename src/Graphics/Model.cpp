#include "Model.hpp"

void Model::init(Mesh mesh, Material material)
{
  mMesh = mesh;
  mMaterial = material;
}

Mesh& Model::getMesh()
{
  return mMesh;
}

Material& Model::getMaterial()
{
  return mMaterial;
}

glm::mat4 Model::getModelMatrix()
{
  return mModelMatrix;
}
