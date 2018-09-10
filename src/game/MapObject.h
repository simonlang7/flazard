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

#ifndef FLAZARD_MAPOBJECT_H
#define FLAZARD_MAPOBJECT_H

#include <string>
#include "../utility/types.h"
#include "Entity.h"

/**
 * An entity that is located on a map
 */
class MapObject {
public:
    MapObject(const std::string& name, const Point& spawnCoordinates);
    virtual ~MapObject();

    virtual void update(float elapsedTime);
    virtual void draw(const Renderer& renderer, Point position);

    const std::string& getName() const;

    Entity& getEntity();

    const Point& getCoordinates() const;

    const Point& getOffset() const;

private:
    std::string name;
    Entity entity;
    Point coordinates;
    Point offset;
    Vector2 velocity;

};


#endif //FLAZARD_MAPOBJECT_H
