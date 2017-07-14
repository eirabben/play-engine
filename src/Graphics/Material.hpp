#pragma once
#include "Texture.hpp"

class Material
{
public:
  void init(Texture diffuse, Texture specular, float shininess);

  Texture& getDiffuse();
  Texture& getSpecular();
  float getShininess();

private:
  Texture mDiffuse;
  Texture mSpecular;
  float mShininess;

};
