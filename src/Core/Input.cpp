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

void Input::mouseMoved(double xPos, double yPos)
{
}

void Input::wheelMoved(double xOffset, double yOffset)
{
}

void Input::update()
{
  for (auto& binding : mKeyDownBindings)
  {
    auto key = mKeysDown.find(binding.first);
    if (key != mKeysDown.end())
    {
      callAction(binding.second);
    }
  }
}

void Input::addAction(std::string name, std::function<void()> action)
{
  mActions[name] = action;
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

void Input::callAction(std::string name)
{
  auto action = mActions.find(name);
  if (action != mActions.end())
  {
    mActions[name]();
  }
}

