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

#include "InputMapping.h"
#include "../../utility/Logger.h"

InputMapping::InputMapping() = default;

InputMapping::~InputMapping() = default;

const InputAction& InputMapping::inputActionFor(const SDL_Keycode& keycode) {
    return this->inputActionMap[keycode];
}

const InputState& InputMapping::inputStateFor(const SDL_Keycode& keycode) {
    return this->inputStateMap[keycode];
}

void InputMapping::putInputAction(const SDL_Keycode& keycode, const InputAction action) {
    this->inputActionMap[keycode] = action;
}

void InputMapping::putInputState(const SDL_Keycode& keycode, const InputState state) {
    this->inputStateMap[keycode] = state;
}


