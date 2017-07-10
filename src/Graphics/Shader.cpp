#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

void Shader::init(std::string vertexShaderPath, std::string fragmentShaderPath)
{
  std::string vertexShaderSource = loadShader(vertexShaderPath);
  std::string fragmentShaderSource = loadShader(fragmentShaderPath);

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  compileShader(vertexShader, vertexShaderSource.c_str());

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  compileShader(fragmentShader, fragmentShaderSource.c_str());

  linkProgram(vertexShader, fragmentShader);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::use() {
    glUseProgram(mId);
}

int Shader::getUniformLocation(const std::string& name)
{
  return glGetUniformLocation(mId, name.c_str());
}

void Shader::setBool(const std::string& name, bool value)
{
  glUniform1i(getUniformLocation(name), (int)value);
}

void Shader::setInt(const std::string& name, int value)
{
  glUniform1i(getUniformLocation(name), value);
}

void Shader::setFloat(const std::string& name, float value)
{
  glUniform1f(getUniformLocation(name), value);
}

void Shader::setVec2(const std::string& name, glm::vec2 value)
{
  glUniform2fv(getUniformLocation(name), 1, glm::value_ptr(value));
}

void Shader::setVec3(const std::string& name, glm::vec3 value)
{
  glUniform3fv(getUniformLocation(name), 1, glm::value_ptr(value));
}

void Shader::setMat4(const std::string& name, glm::mat4 value)
{
  glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}

std::string Shader::loadShader(std::string path)
{
  std::string source;
  std::ifstream file;

  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    file.open(path);
    std::stringstream stream;

    stream << file.rdbuf();

    file.close();

    source = stream.str();
  }
  catch (std::ifstream::failure e)
  {
    std::cout << "Error reading shader file: " << path << "\n";
  }

  return source;
}

void Shader::compileShader(unsigned int shader, const char* source)
{
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);

  int success;
  char infoLog[1024];

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
    std::cout << "Error compiling shader: " << "\n" << infoLog << "\n";
  }
}

void Shader::linkProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
  mId = glCreateProgram();

  glAttachShader(mId, vertexShader);
  glAttachShader(mId, fragmentShader);

  glLinkProgram(mId);

  int success;
  char infoLog[1024];

  glGetProgramiv(mId, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(mId, 1024, NULL, infoLog);
    std::cout << "Error linking program: " << "\n" << infoLog << "\n";
  }
}

