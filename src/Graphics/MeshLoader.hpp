#pragma once
#include <vector>
#include "Mesh.hpp"

class MeshLoader
{
public:
  Mesh loadMesh(std::vector<float> vertices, std::vector<unsigned int> indices);

private:

};
