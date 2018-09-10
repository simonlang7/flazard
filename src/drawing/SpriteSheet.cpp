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

#include "SpriteSheet.h"
#include <utility>
#include "Renderer.h"

SpriteSheet::SpriteSheet(const SpriteSheetData& data, const Texture& texture) :
    data(data), texture(texture) {
}

void SpriteSheet::draw(const Renderer& renderer, const int index, const Vector2& position) {
    const Rect& source = (*this)[index];
    renderer.draw(texture, source, position, data.frameSize);
}

Rect SpriteSheet::operator[](const int index) {
    int row = index / data.framesPerRow;
    int col = index % data.framesPerRow;
    int x = data.initialHOffset + col*(data.frameSize.w + data.hSpaceBetweenFrames);
    int y = data.initialVOffset + row*(data.frameSize.h + data.vSpaceBetweenFrames);
    return Rect(x, y, data.frameSize.w, data.frameSize.h);
}

const std::string& SpriteSheet::getName() const {
    return data.name;
}
