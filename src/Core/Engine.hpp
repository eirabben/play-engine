#pragma once
#include "Window.hpp"
#include "Game.hpp"
#include "Input.hpp"

class Engine
{
public:
  void boot();
  void loop();
  void shutdown();

  void handleInput(int key, int scancode, int action, int mods);
  void handleMouse(double xPos, double yPos);
  void handleScroll(double xOffset, double yOffset);

private:
  Window mWindow;
  Game mGame;
  Input mInput;

};
