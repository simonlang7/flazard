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

#ifndef FLAZARD_PLAYERACTIONINPUT_H
#define FLAZARD_PLAYERACTIONINPUT_H


#include "input_types.h"

/**
 * One-shot input actions (typically read within a single frame) tied to a player
 */
struct PlayerActionInput {
public:
    PlayerActionInput(unsigned player = 0,
                      InputAction action = ACTION_NONE,
                      InputType type = TYPE_NONE,
                      bool repeat = false);
    ~PlayerActionInput();

    // Operators for comparison / sorting
    bool operator<(const PlayerActionInput& rhs) const;
    bool operator>(const PlayerActionInput& rhs) const;
    bool operator==(const PlayerActionInput& rhs) const;

    /** Number of the player executing the action */
    unsigned player;
    /** Action to be executed */
    InputAction action;
    /** Whether the key or button is pressed or released */
    InputType type;
    /** Whether to repeat the event after some time (i.e. the key or button is held) */
    bool repeat;
};


#endif //FLAZARD_PLAYERACTIONINPUT_H
