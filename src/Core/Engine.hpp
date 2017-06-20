#pragma once_flag
#include "Window.hpp"

class Engine
{
public:
  void boot();
  void loop();
  void shutdown();

private:
  Window mWindow;
  // Game mGame;

};