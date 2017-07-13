#include "Engine.hpp"
#include <iostream>

void Engine::boot()
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialize GLFW.\n";
  }

  mWindow.create(1280, 720, "PlayEngine");
  mWindow.setWindowUserPointer(mGame);

  mGame.load();

  loop();
}

void Engine::loop()
{
  // http://gameprogrammingpatterns.com/game-loop.html
  const double msPerUpdate = 1 / 60.0;
  double prevTime = glfwGetTime();
  double lag = 0.0;
  while (!mWindow.shouldClose())
  {
    double currentTime = glfwGetTime();
    double elapsed = currentTime - prevTime;
    prevTime = currentTime;
    lag += elapsed;
    glfwPollEvents();
    while (lag >= msPerUpdate)
    {
      mGame.update(msPerUpdate);
      lag -= msPerUpdate;
    }
    mGame.draw();
    mWindow.swapBuffers();
  }

  shutdown();
}

void Engine::shutdown()
{
  mGame.quit();
  mWindow.destroy();
  glfwTerminate();
}

