#pragma once
#include <string>
#include <GLFW/Glfw3.h>

class Game;

class Window
{
public:
  void create(int width, int height, std::string title);
  static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
  void swapBuffers();
  bool shouldClose();
  void destroy();

  void setWindowUserPointer(Game& game);
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void cursorPosCallback(GLFWwindow* window, double xPos, double yPos);
  static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

private:
  GLFWwindow* mWindow;
  
};
