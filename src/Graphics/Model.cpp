#include "Model.hpp"

void Model::init(unsigned int vao)
{
  mVao = vao;
}

unsigned int Model::getVao()
{
  return mVao;
}
