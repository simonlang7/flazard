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

#ifndef FLAZARD_INPUTMAPPING_H
#define FLAZARD_INPUTMAPPING_H

#include <SDL.h>
#include <unordered_map>
#include "../../utility/types.h"

#define KEYS "keys"
#define INPUT "input"
#define INPUT_ACTIONS "inputActions"
#define INPUT_STATES "inputStates"

/**
 * Defines a mapping of keycodes to input actions and input states, essentially a
 * control scheme for the player
 */
class InputMapping {
public:
    InputMapping();
    ~InputMapping();

    const InputAction& inputActionFor(const SDL_Keycode& keycode);
    const InputState& inputStateFor(const SDL_Keycode& keycode);

    void putInputAction(const SDL_Keycode& keycode, const InputAction action);
    void putInputState(const SDL_Keycode& keycode, const InputState state);


private:
    std::unordered_map<SDL_Keycode, InputAction> inputActionMap;
    std::unordered_map<SDL_Keycode, InputState> inputStateMap;
    friend class Serializer;
};



#endif //FLAZARD_INPUTMAPPING_H
