/* ==================================================================== *
 *
 * Flazard Game Engine
 * Copyright (C) 2018 Simon Lang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * ==================================================================== */

#include "Game.h"

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <SDL.h>

#include "resource/resource_util.h"
#include "drawing/Renderer.h"
#include "drawing/SpriteSheet.h"
#include "drawing/SpriteAnimation.h"
#include "input/PlayerActionInput.h"
#include "input/InputManager.h"
#include "utility/collection_util.h"
#include "screen/DemoScreen.h"
#include "screen/ScreenManager.h"
#include "utility/Logger.h"
#include "resource/ResourceManager.h"

using namespace std::chrono;

std::chrono::duration<double, std::milli> Game::timestep(16);

int Game::run() {
    {
        ErrorContext errorContext("In main", "");
        Logger::init();
        try {
            using clock = std::chrono::high_resolution_clock;

            InputManager inputManager(ResourceManager::load<InputMapping>(
                    getResourcePath("controls"), "default.json"));

            std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>(1280, 720);
            ScreenManager screenManager(renderer);
            screenManager.pushScreen(std::make_shared<DemoScreen>(renderer));

            std::chrono::duration<double, std::milli> lag(0);
            auto start = clock::now();

            bool quit = false;
            while (!quit) {
                std::chrono::duration<double, std::milli> elapsed = clock::now() - start;
                start = clock::now();
                lag += std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);

                // Update
                while (lag >= timestep && !quit) {
                    lag -= timestep;

                    // Process input
                    auto [currentActions, currentStates] = inputManager.update();
                    if (inputManager.quitRequested())
                        quit = true;

                    // Update screens
                    screenManager.handleInput(currentActions, currentStates);
                    screenManager.update(timestep.count());
                }

                // Render
                screenManager.draw();
            }
            screenManager.clear();
        } catch (FatalError& fatalError) {
            // This only serves the purpose of destroying the renderer
            // and cleaning up any loaded textures
            exitWithFailure(1);
        }
    }

    Logger::destroy();
    return 0;
}
