#include "ModelLoader.hpp"
#include "Model.hpp"
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

void ModelLoader::loadModel(Model& model, std::vector<float> vertices)
{
  unsigned int vao = createVao();
  storeAttribData(0, vertices);
  unbindVao();

  model.init(vao, vertices.size() / 3);
}

void ModelLoader::cleanUp()
{
  for (auto vao : mVaos)
  {
    // glDeleteVertexArrays(&vao);
  }

  for (auto &vbo : mVbos)
  {
    // glDeleteBuffers(&vbo);
  }
}

unsigned int ModelLoader::createVao()
{
  unsigned int vao;
  glGenVertexArrays(1, &vao);

  mVaos.push_back(vao);

  glBindVertexArray(vao);
  return vao;
}

void ModelLoader::storeAttribData(int index, std::vector<float> data)
{
  unsigned int vbo;
  glGenBuffers(1, &vbo);
  mVbos.push_back(vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ModelLoader::unbindVao()
{
  glBindVertexArray(0);
}