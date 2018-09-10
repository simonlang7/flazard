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

#ifndef FLAZARD_INPUTMANAGER_H
#define FLAZARD_INPUTMANAGER_H


#include <vector>
#include <memory>
#include <unordered_map>
#include <set>
#include "PlayerActionInput.h"
#include "../utility/types.h"
#include "PlayerStateInput.h"
#include "mapping/InputMapping.h"

/**
 * Lists of input actions and input states from all players at a specific point in time
 * (typically a new one each frame)
 */
struct Input {
    Input(std::list<PlayerActionInput>& actions, std::list<PlayerStateInput>& states);
    const std::list<PlayerActionInput>& actions;
    const std::list<PlayerStateInput>& states;
};

/**
 * Retrieves input from devices and transforms it to logical input for the game
 */
class InputManager {
public:
    explicit InputManager(std::unique_ptr<InputMapping> inputMapping);
    ~InputManager();

    /**
     * Checks the devices for input and returns logical input
     */
    Input update();

    /**
     * True if the user has requested to quit the game, false otherwise
     */
    bool quitRequested();

private:
    void updateKeyboardInput(SDL_Event &event);

    std::list<PlayerActionInput> currentActions;
    std::list<PlayerStateInput> currentStates;
    SDL_Event event;
    bool isQuitRequested;
    std::unique_ptr<InputMapping> inputMapping;
};


#endif //FLAZARD_INPUTMANAGER_H
