#pragma once
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    void compileShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    void compileShader(GLuint shaderID, const GLchar* shaderSource);
    void linkShaders(GLuint vertexShaderID, GLuint fragmentShaderID);
    std::string loadSourceFromFile(const std::string& shaderPath);

    GLint getUniformLocation(const std::string& uniformName) const;
    void loadUniform(GLint location, int data);
    void loadUniform(GLint location, float data);
    void loadUniform(GLint location, glm::vec2 data);
    void loadUniform(GLint location, glm::vec3 data);
    void loadUniform(GLint location, glm::mat4 data);

    void use();
    void unuse();

private:
    GLuint program;

};
