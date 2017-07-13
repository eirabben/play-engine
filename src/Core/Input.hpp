#pragma once
#include <string>
#include <map>

class Input
{
public:
  // Events
  void keyPressed(int key);
  void keyReleased(int key);

  void mouseMoved(double x, double y);
  void wheelMoved(double offsetX, double offsetY);

  void update(double dt);

  // Mappers
  void addAction(std::string name, std::function<void()> action);
  void addAction(std::string name, std::function<void(double)> action);
  void bindKeyPress(int key, std::string action);
  void bindKeyRelease(int key, std::string action);
  void bindKeyDown(int key, std::string action);
  void bindMouseMove(std::function<void(double, double, double, double)> action);

private:
  // Bindings
  std::map<std::string, std::function<void()>> mActions;
  std::map<std::string, std::function<void(double)>> mTimedActions;
  std::map<int, std::string> mKeyPressBindings;
  std::map<int, std::string> mKeyReleaseBindings;
  std::map<int, std::string> mKeyDownBindings;
  std::function<void(double, double, double, double)> mMouseMoveBinding;

  // State
  std::map<int, bool> mKeysDown;
  double mMouseX = 0;
  double mMouseY = 0;
  bool mFirstMouse = true;

  // Helpers
  void callAction(std::string name);
  void callTimedAction(std::string name, double dt);

};
