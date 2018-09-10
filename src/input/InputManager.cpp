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

#include <SDL.h>
#include "InputManager.h"
#include "../resource/resource_util.h"
#include "../screen/ScreenManager.h"
#include "../resource/ResourceManager.h"


Input::Input(std::list<PlayerActionInput>& actions, std::list<PlayerStateInput>& states)
        : actions(actions), states(states) { }


InputManager::InputManager(std::unique_ptr<InputMapping> inputMapping) {
    this->inputMapping = std::move(inputMapping);
    this->isQuitRequested = false;
}

InputManager::~InputManager() = default;


Input InputManager::update() {
    ErrorContext errorContext("InputManager: Getting PlayerActions", "");

    currentActions.clear();

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isQuitRequested = true;
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                    updateKeyboardInput(event);
                break;
            default:
                break;
        }
    }

    return Input(currentActions, currentStates);
}

bool InputManager::quitRequested() {
    return isQuitRequested;
}

void InputManager::updateKeyboardInput(SDL_Event &event) {
    InputType type = event.type == SDL_KEYDOWN ? TYPE_PRESS : TYPE_RELEASE;
    bool repeat = event.key.repeat;
    const InputAction& inputAction = inputMapping->inputActionFor(event.key.keysym.sym);
    const InputState& inputState = inputMapping->inputStateFor(event.key.keysym.sym);

    currentActions.emplace_back(PlayerActionInput(0, inputAction, type, repeat));
    if (type == TYPE_PRESS && !repeat)
        currentStates.emplace_back(PlayerStateInput(0, inputState));
    if (type == TYPE_RELEASE)
        currentStates.remove(PlayerStateInput(0, inputState));

}