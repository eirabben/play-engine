#include "Mesh.hpp"

void Mesh::init(unsigned int vao)
{
  mVao = vao;
}

unsigned int Mesh::getVao()
{
  return mVao;
}
