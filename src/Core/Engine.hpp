#pragma once
#include "Window.hpp"
#include "Game.hpp"

class Engine
{
public:
  void boot();
  void loop();
  void shutdown();

private:
  Window mWindow;
  Game mGame;

};
