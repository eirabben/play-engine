#include "Renderer.hpp"
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

void Renderer::render(Model& model)
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glBindVertexArray(model.getVao());

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
