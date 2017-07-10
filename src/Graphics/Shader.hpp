#pragma once
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
  void init(std::string vertexShaderPath, std::string fragmentShaderPath);

  void use();

  int getUniformLocation(const std::string& name);
  void setBool(const std::string& name, bool value);
  void setInt(const std::string& name, int value);
  void setFloat(const std::string& name, float value);
  void setVec2(const std::string& name, glm::vec2 value);
  void setVec3(const std::string& name, glm::vec3 value);
  void setMat4(const std::string& name, glm::mat4 value);

private:
  unsigned int mId;

  std::string loadShader(std::string path);
  void compileShader(unsigned int id, const char* source);
  void linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
};
