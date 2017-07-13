#include "Window.hpp"
#include <iostream>
#include "Engine.hpp"

void Window::create(int width, int height, std::string title)
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  mWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  if (mWindow == NULL)
  {
    std::cout << "Could not create GLFW window\n";
  }

  glfwMakeContextCurrent(mWindow);
  glfwSetFramebufferSizeCallback(mWindow, framebufferSizeCallback);

  /* glfwSwapInterval(1); */

  /* glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED); */
  /* glfwSetCursorPos(mWindow, 0, 0); */

  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mWindow, &bufferWidth, &bufferHeight);
  glViewport(0, 0, bufferWidth, bufferHeight);

  glEnable(GL_DEPTH_TEST);
  // glDepthFunc(GL_LESS);
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void Window::swapBuffers()
{
  glfwSwapBuffers(mWindow);
}

bool Window::shouldClose()
{
  return glfwWindowShouldClose(mWindow);
}

void Window::destroy()
{
  glfwDestroyWindow(mWindow);
}

void Window::setWindowUserPointer(Engine* engine)
{
  glfwSetWindowUserPointer(mWindow, engine);

  glfwSetKeyCallback(mWindow, keyCallback);
  glfwSetCursorPosCallback(mWindow, cursorPosCallback);
  glfwSetScrollCallback(mWindow, scrollCallback);
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  Engine* engine = reinterpret_cast<Engine*>(glfwGetWindowUserPointer(window));
  engine->handleInput(key, scancode, action, mods);
}

void Window::cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
{
  Engine* engine = reinterpret_cast<Engine*>(glfwGetWindowUserPointer(window));
  engine->handleMouse(xPos, yPos);
}

void Window::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
  Engine* engine = reinterpret_cast<Engine*>(glfwGetWindowUserPointer(window));
  engine->handleScroll(xOffset, yOffset);
}
