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

#include "MapObject.h"

MapObject::MapObject(const std::string& name, const Point& spawnCoordinates) :
        name(name), coordinates(spawnCoordinates),
        offset(0, 0), velocity(0, 0) {
}

MapObject::~MapObject() {

}

void MapObject::update(float elapsedTime) {

}

void MapObject::draw(const Renderer& renderer, Point position) {

}

const std::string& MapObject::getName() const {
    return name;
}

Entity& MapObject::getEntity() {
    return entity;
}

const Point &MapObject::getCoordinates() const {
    return coordinates;
}

const Point &MapObject::getOffset() const {
    return offset;
}