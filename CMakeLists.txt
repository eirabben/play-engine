cmake_minimum_required(VERSION 3.7.0)

project(PlayEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(Lua REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(engine
  src/main.cpp
  src/Core/Engine.cpp
  src/Core/Window.cpp
  src/Core/Game.cpp
  src/Graphics/Shader.cpp
  src/Graphics/MeshLoader.cpp
  src/Graphics/Mesh.cpp
  src/Graphics/Camera.cpp
  src/Graphics/Model.cpp
  src/Graphics/Renderer.cpp
  src/Graphics/Texture.cpp
  src/Graphics/TextureLoader.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_SOURCE_DIR}/lib/include)

target_link_libraries(engine Lua glfw ${OPENGL_gl_LIBRARY})

install(TARGETS engine DESTINATION ${CMAKE_SOURCE_DIR}/bin)

