#pragma once
#include <string>
#include <map>
#include <functional>

class Input
{
public:
  // Events
  void keyPressed(int key);
  void keyReleased(int key);

  void mouseMoved(double xPos, double yPos);
  void wheelMoved(double xOffset, double yOffset);

  void update();

  // Mappers
  void addAction(std::string name, std::function<void()> action);
  void bindKeyPress(int key, std::string action);
  void bindKeyRelease(int key, std::string action);
  void bindKeyDown(int key, std::string action);

private:
  // Bindings
  std::map<std::string, std::function<void()>> mActions;
  std::map<int, std::string> mKeyPressBindings;
  std::map<int, std::string> mKeyReleaseBindings;
  std::map<int, std::string> mKeyDownBindings;

  // State
  std::map<int, bool> mKeysDown;

  // Helpers
  void callAction(std::string name);

};
