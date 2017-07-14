#include "Renderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

void Renderer::render(Camera& camera, Shader& shader, Model& model, DirectionalLight& dirLight, PointLight& pointLight)
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shader.use();

  // Camera settings
  glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), (float)1280 / (float)720, 0.1f, 100.0f);
  shader.setMat4("projection", projection);
  shader.setMat4("view", camera.getViewMatrix());
  shader.setVec3("viewPosition", camera.getPosition());

  // Object settings
  shader.setMat4("model", model.getModelMatrix());

  // Light
  shader.setVec3("dirLight.direction", dirLight.getDirection());
  shader.setVec3("dirLight.ambient", dirLight.getAmbient());
  shader.setVec3("dirLight.diffuse", dirLight.getDiffuse());
  shader.setVec3("dirLight.specular", dirLight.getSpecular());

  shader.setVec3("pointLights[0].position", pointLight.getPosition());
  shader.setVec3("pointLights[0].ambient", pointLight.getAmbient());
  shader.setVec3("pointLights[0].diffuse", pointLight.getDiffuse());
  shader.setVec3("pointLights[0].specular", pointLight.getSpecular());
  shader.setFloat("pointLights[0].constant", pointLight.getConstant());
  shader.setFloat("pointLights[0].linear", pointLight.getLinear());
  shader.setFloat("pointLights[0].quadratic", pointLight.getQuadratic());

  // Material
  shader.setInt("material.diffuse", 0);
  shader.setInt("material.specular", 1);
  shader.setFloat("material.shininess", model.getMaterial().getShininess());

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, model.getMaterial().getDiffuse().getId());

  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, model.getMaterial().getSpecular().getId());

  glBindVertexArray(model.getMesh().getVao());
  glDrawArrays(GL_TRIANGLES, 0, 36);

}
