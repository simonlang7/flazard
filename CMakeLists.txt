cmake_minimum_required(VERSION 3.5)
project(flazard)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/include/json.hpp src/resource/resource_util.cpp src/resource/resource_util.h src/utility/ErrorContext.cpp src/utility/ErrorContext.h src/drawing/Renderer.cpp src/drawing/Renderer.h src/drawing/Texture.cpp src/drawing/Texture.h src/utility/types.cpp src/utility/types.h src/Game.cpp src/Game.h src/drawing/SpriteAnimation.cpp src/drawing/SpriteAnimation.h src/drawing/SpriteSheet.cpp src/drawing/SpriteSheet.h src/game/MapObject.cpp src/game/MapObject.h src/game/Character.cpp src/game/Character.h src/input/InputManager.cpp src/input/InputManager.h src/input/input_types.h src/input/PlayerActionInput.cpp src/input/PlayerActionInput.h src/screen/Screen.h src/utility/collection_util.h src/screen/DemoScreen.cpp src/screen/DemoScreen.h src/screen/Screen.cpp src/input/PlayerStateInput.cpp src/input/PlayerStateInput.h src/screen/ScreenManager.cpp src/screen/ScreenManager.h src/input/mapping/InputMapping.cpp src/input/mapping/InputMapping.h src/utility/Logger.cpp src/utility/Logger.h src/game/Entity.cpp src/game/Entity.h src/resource/ResourceManager.cpp src/resource/ResourceManager.h src/resource/Serializer.cpp src/resource/Serializer.h)
add_executable(flazard ${SOURCE_FILES})

#INCLUDE(FindPkgConfig)
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${INCLUDE_DIRECTORIES} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})