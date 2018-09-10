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

#ifndef FLAZARD_OBJECT_H
#define FLAZARD_OBJECT_H


#include <string>
#include <unordered_map>
#include "../drawing/SpriteSheet.h"
#include "../drawing/SpriteAnimation.h"

/**
 * Object on the screen that has animations and can be drawn
 */
class Entity {
public:
    Entity();

    /**
     * Draw the object to the given renderer at the given position
     */
    void draw(const Renderer& renderer, Vector2& position);

    const std::string& getName() const;

private:
    std::string name;
    std::unordered_map<std::string, std::shared_ptr<SpriteAnimation>> spriteAnimations;
    std::shared_ptr<SpriteAnimation> currentSpriteAnimation;
    friend class Serializer;
};


#endif //FLAZARD_OBJECT_H
