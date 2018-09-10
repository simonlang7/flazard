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

#include "types.h"

Rect::Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) { }

Rect::Rect(const Rect& other) = default;

Point::Point(int x, int y) : x(x), y(y) { }

Point::Point(const Point& other) = default;

Dimension::Dimension(int w, int h) : w(w), h(h) { }

Dimension::Dimension(const Dimension& other) = default;

Vector2::Vector2(float x, float y) : x(x), y(y) { }

Vector2::Vector2(const Vector2& other) = default;

Vector2::Vector2(const Point& point) : x(point.x), y(point.y) { }

