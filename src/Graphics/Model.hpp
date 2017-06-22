#pragma once

class Model
{
public:
  void init(unsigned int vao, unsigned int vertexCount);

  unsigned int getVao();
  unsigned int getVertexCount();

private:
  unsigned int mVao;
  unsigned int mVertexCount;

};