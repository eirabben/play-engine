#include "Input.hpp"
#include <iostream>
#include <GLFW/Glfw3.h>

void Input::keyPressed(int key)
{
  mKeysDown[key] = true;

  auto binding = mKeyPressBindings.find(key);
  if (binding != mKeyPressBindings.end())
  {
    callAction(binding->second);
  }
}

void Input::keyReleased(int key)
{
  mKeysDown.erase(key);

  auto binding = mKeyReleaseBindings.find(key);
  if (binding != mKeyReleaseBindings.end())
  {
    callAction(binding->second);
  }
}

void Input::mouseMoved(double x, double y)
{
  if (mFirstMouse)
  {
    mMouseX = x;
    mMouseY = y;
    mFirstMouse = false;
  }

  double offsetX = x - mMouseX;
  double offsetY = mMouseY - y; // y-coordinates go from bottom to top

  if (mMouseMoveBinding)
  {
    mMouseMoveBinding(x, y, offsetX, offsetY);
  }

  mMouseX = x;
  mMouseY = y;
}

void Input::wheelMoved(double offsetX, double offsetY)
{
}

void Input::update(double dt)
{
  for (auto& binding : mKeyDownBindings)
  {
    auto key = mKeysDown.find(binding.first);
    if (key != mKeysDown.end())
    {
      callTimedAction(binding.second, dt);
    }
  }
}

void Input::addAction(std::string name, std::function<void()> action)
{
  mActions[name] = action;
}

void Input::addAction(std::string name, std::function<void(double)> action)
{
  mTimedActions[name] = action;
}

void Input::bindKeyPress(int key, std::string action)
{
  mKeyPressBindings[key] = action;
}

void Input::bindKeyRelease(int key, std::string action)
{
  mKeyReleaseBindings[key] = action;
}

void Input::bindKeyDown(int key, std::string action)
{
  mKeyDownBindings[key] = action;
}

void Input::bindMouseMove(std::function<void(double, double, double, double)> action)
{
  mMouseMoveBinding = action;
}

void Input::callAction(std::string name)
{
  auto action = mActions.find(name);
  if (action != mActions.end())
  {
    mActions[name]();
  }
}

void Input::callTimedAction(std::string name, double dt)
{
  auto action = mTimedActions.find(name);
  if (action != mTimedActions.end())
  {
    mTimedActions[name](dt);
  }
}

