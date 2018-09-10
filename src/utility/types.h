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

#ifndef FLAZARD_TYPES_H
#define FLAZARD_TYPES_H

#include <list>
#include <memory>
#include "../input/PlayerActionInput.h"
#include "../input/PlayerStateInput.h"

typedef std::list<PlayerActionInput> PlayerActions;
typedef std::list<PlayerStateInput> PlayerStates;

struct Rect {
    explicit Rect(int x = 0, int y = 0, int w = 0, int h = 0);
    Rect(const Rect& other);
    int x, y, w, h;
};

struct Point {
    explicit Point(int x = 0, int y = 0);
    Point(const Point& other);
    int x, y;
};

struct Dimension {
    explicit Dimension(int w = 0, int h = 0);
    Dimension(const Dimension& other);
    int w, h;
};

struct Vector2 {
    explicit Vector2(float x = 0.0f, float y = 0.0f);
    Vector2(const Vector2& other);
    explicit Vector2(const Point& point);
    float x, y;
};

template<typename T, typename S>
struct Pair {
    Pair(T first, S second) : first(first), second(second) { }
    Pair(const Pair<T, S>& other) : first(other.first), second(other.second) { }
    T first;
    S second;
};

class FatalError : std::exception {
};


#endif //FLAZARD_TYPES_H
