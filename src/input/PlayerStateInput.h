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

#ifndef FLAZARD_PLAYERSTATEINPUT_H
#define FLAZARD_PLAYERSTATEINPUT_H


#include "input_types.h"

/**
 * States of input (such as walking), typically processed over several frames,
 * tied to a player
 */
class PlayerStateInput {
public:
    PlayerStateInput(unsigned player = 0, InputState state = STATE_NONE);
    ~PlayerStateInput();

    // Operators for comparison / sorting
    bool operator<(const PlayerStateInput& rhs) const;
    bool operator>(const PlayerStateInput& rhs) const;
    bool operator==(const PlayerStateInput& rhs) const;

    /** Number of the player */
    unsigned player;
    /** State the player is or wants to be in */
    InputState state;
};


#endif //FLAZARD_PLAYERSTATEINPUT_H
