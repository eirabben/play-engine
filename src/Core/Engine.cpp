#include "Engine.hpp"
#include <iostream>

void Engine::boot()
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialize GLFW.\n";
  }

  mWindow.create(1280, 720, "PlayEngine");
  mWindow.setWindowUserPointer(this);

  mGame.load();

  mInput.addAction("JUMP", []() { std::cout << "JUMPING\n"; });
  mInput.bindKeyPress(GLFW_KEY_W, "JUMP");
  mInput.bindKeyRelease(GLFW_KEY_S, "STOP");
  mInput.bindKeyDown(GLFW_KEY_A, "JUMP");

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
      mInput.update();
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

void Engine::handleInput(int key, int scancode, int action, int mods)
{
  if (action == GLFW_PRESS)
  {
    mInput.keyPressed(key);
  }

  if (action == GLFW_RELEASE)
  {
    mInput.keyReleased(key);
  }
}

void Engine::handleMouse(double xPos, double yPos)
{
  mInput.mouseMoved(xPos, yPos);
}

void Engine::handleScroll(double xOffset, double yOffset)
{
  mInput.wheelMoved(xOffset, yOffset);
}

