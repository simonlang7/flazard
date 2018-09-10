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

#include <tuple>
#include "PlayerStateInput.h"

PlayerStateInput::PlayerStateInput(unsigned player, InputState state)
        : player(player),
          state(state) { }

PlayerStateInput::~PlayerStateInput() { }

bool PlayerStateInput::operator<(const PlayerStateInput &rhs) const {
    return std::tie(player, state) < std::tie(rhs.player, rhs.state);
}

bool PlayerStateInput::operator>(const PlayerStateInput &rhs) const {
    return std::tie(player, state) > std::tie(rhs.player, rhs.state);
}

bool PlayerStateInput::operator==(const PlayerStateInput &rhs) const {
    return std::tie(player, state) == std::tie(rhs.player, rhs.state);
}
