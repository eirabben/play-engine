#pragma once

class Mesh
{
public:
  void init(unsigned int vao);

  unsigned int getVao();

private:
  unsigned int mVao;

};
