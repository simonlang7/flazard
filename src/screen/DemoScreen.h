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

#ifndef FLAZARD_DEMOSCREEN_H
#define FLAZARD_DEMOSCREEN_H


#include "Screen.h"

#include <set>
#include "../drawing/SpriteAnimation.h"

/**
 * For everything testing-related
 */
class DemoScreen : public Screen {
public:
    DemoScreen(std::shared_ptr<Renderer> renderer);
    ~DemoScreen();

    void handleInput(const PlayerActions& actions, const PlayerStates& states) override;
    void update(double elapsedTime) override;

    void draw(const Renderer& renderer) override;

private:
    std::unordered_map<InputState, std::shared_ptr<SpriteAnimation>> animations;
    std::shared_ptr<SpriteAnimation> currentAnimation;
    std::unique_ptr<Vector2> position;
    InputState movementDirection;

    void updatePlayerAnimation();
};


#endif //FLAZARD_DEMOSCREEN_H
