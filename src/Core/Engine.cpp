#include "Engine.hpp"

void Engine::boot()
{
  // glfwSetErrorCallback(LogManager::glfwError);

  if (!glfwInit())
  {
    // LogManager::error("Failed to initialize GLFW.");
  }

  // sol::state lua;
  // lua.open_libraries(sol::lib::base, sol::lib::package);
  // lua["game"] = lua.create_table_with();
  // sol::table t = lua.create_table_with(
  //   "window", lua.create_table_with(
  //     "title", "PlayEngine",
  //     "width", 800,
  //     "height", 600
  //   )
  // );
  // sol::load_result conf = lua.load_file("game/conf.lua");
  // if (conf)
  // {
  //   conf();
  //   lua["game"]["conf"](t);
  // }

  mWindow.create(1280, 720, "PlayEngine");
  // mWindow.setWindowUserPointer(mGame);

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