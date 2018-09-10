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
#include "PlayerActionInput.h"

PlayerActionInput::PlayerActionInput(unsigned player,
                                     InputAction action,
                                     InputType type,
                                     bool repeat)
        : player(player),
          action(action),
          type(type),
          repeat(repeat) { }

PlayerActionInput::~PlayerActionInput() { }

bool PlayerActionInput::operator<(const PlayerActionInput& rhs) const {
    return std::tie(player, action, type, repeat) < std::tie(rhs.player, rhs.action, rhs.type, rhs.repeat);
}

bool PlayerActionInput::operator>(const PlayerActionInput& rhs) const {
    return std::tie(player, action, type, repeat) > std::tie(rhs.player, rhs.action, rhs.type, rhs.repeat);
}

bool PlayerActionInput::operator==(const PlayerActionInput& rhs) const {
    return std::tie(player, action, type, repeat) == std::tie(rhs.player, rhs.action, rhs.type, rhs.repeat);
}
