#pragma once
#include <string>
#include <GLFW/Glfw3.h>

class Window
{
public:
  void create(int width, int height, std::string title);
  static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
  void swapBuffers();
  bool shouldClose();
  void destroy();

  // void setWindowUserPointer(Game& game);
  // static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
  GLFWwindow* mWindow;
  
};
