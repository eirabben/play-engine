#include "Window.hpp"
#include <iostream>
#include "Game.hpp"

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

  glfwSwapInterval(1);

  glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwSetCursorPos(mWindow, 0, 0);

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

void Window::setWindowUserPointer(Game& game)
{
  glfwSetWindowUserPointer(mWindow, &game);

  glfwSetKeyCallback(mWindow, keyCallback);
  glfwSetCursorPosCallback(mWindow, cursorPosCallback);
  glfwSetScrollCallback(mWindow, scrollCallback);
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
  game->handleInput(key, scancode, action, mods);
}

void Window::cursorPosCallback(GLFWwindow* window, double x, double y)
{
  Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
  game->handleMouse(x, y);
}

void Window::scrollCallback(GLFWwindow* window, double offsetX, double offsetY)
{
  Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
  game->handleScroll(offsetX, offsetY);
}
