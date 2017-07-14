#include "Material.hpp"

void Material::init(Texture diffuse, Texture specular, float shininess)
{
  mDiffuse = diffuse;
  mSpecular = specular;
  mShininess = shininess;
}

Texture& Material::getDiffuse()
{
  return mDiffuse;
}

Texture& Material::getSpecular()
{
  return mSpecular;
}

float Material::getShininess()
{
  return mShininess;
}
