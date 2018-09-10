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

#ifndef FLAZARD_SCREEN_H
#define FLAZARD_SCREEN_H


#include <vector>
#include "../input/PlayerActionInput.h"
#include "../utility/types.h"
#include "../drawing/Renderer.h"

/**
 * Basic screen that can be displayed and added to or removed from the screen manager
 */
class Screen {
public:
    /**
     * React to player input
     */
    virtual void handleInput(const PlayerActions& actions, const PlayerStates& states) = 0;

    /**
     * Update screen to the next frame (or by several frames)
     */
    virtual void update(double elapsedTime) = 0;

    /**
     * Draw contents of this screen to the renderer
     */
    virtual void draw(const Renderer& renderer) = 0;
};


#endif //FLAZARD_SCREEN_H
