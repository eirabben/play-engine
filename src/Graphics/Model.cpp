#include "Model.hpp"

void Model::init(unsigned int vao, unsigned int vertexCount)
{
  mVao = vao;
  mVertexCount = vertexCount;
}

unsigned int Model::getVao()
{
  return mVao;
}

unsigned int Model::getVertexCount()
{
  return mVertexCount;
}