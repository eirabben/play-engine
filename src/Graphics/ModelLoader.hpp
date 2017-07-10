#pragma once
#include <vector>
#include "Model.hpp"

class ModelLoader
{
public:
  Model loadModel(std::vector<float> vertices, std::vector<unsigned int> indices);
  /* void loadModel(Model& model, std::vector<float> vertices, std::vector<unsigned int> indices); */
  /* void cleanUp(); */

private:
  /* std::vector<unsigned int> mVaos; */
  /* std::vector<unsigned int> mVbos; */

  /* unsigned int createVao(); */
  /* void storeAttribData(int index, std::vector<float> data); */
  /* void unbindVao(); */

};
