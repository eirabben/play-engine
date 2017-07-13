#include "Renderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

void Renderer::render(Camera& camera, Shader& shader, Model& model)
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBindTexture(GL_TEXTURE_2D, model.getTexture().getId());

  shader.use();

  glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), (float)1280 / (float)720, 0.1f, 100.0f);
  shader.setMat4("projection", projection);
  shader.setMat4("view", camera.getViewMatrix());
  shader.setMat4("model", model.getModelMatrix());

  glBindVertexArray(model.getMesh().getVao());
  glDrawArrays(GL_TRIANGLES, 0, 36);

  /* glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); */

}
