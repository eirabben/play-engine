#include "Renderer.hpp"
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

void Renderer::prepare()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Renderer::render(Model& model)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBindVertexArray(model.getVao());
  glEnableVertexAttribArray(0);
  glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}