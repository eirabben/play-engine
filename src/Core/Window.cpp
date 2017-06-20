#include "Window.hpp"

void Window::create(int width, int height, std::string title)
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if (!mWindow)
  {
    // LogManager::error( "Failed to create GLFW window.");
  }

  glfwMakeContextCurrent(mWindow);
  glfwSwapInterval(1);

  /* glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED); */
  /* glfwSetCursorPos(mWindow, 0, 0); */

  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mWindow, &bufferWidth, &bufferHeight);
  glViewport(0, 0, bufferWidth, bufferHeight);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
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

// void Window::setWindowUserPointer(Game& game) {
//   glfwSetWindowUserPointer(mWindow, &game);

//   glfwSetKeyCallback(mWindow, keyCallback);
// }

// void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//   Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
//   game->handleInput();
// }
