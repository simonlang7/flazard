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

#ifndef FLAZARD_SPRITESHEET_H
#define FLAZARD_SPRITESHEET_H

#include <string>
#include <memory>
#include "Texture.h"
#include "../utility/types.h"
#include "Renderer.h"

/**
 * Data defining the sprite sheet without containing the actual graphics
 */
struct SpriteSheetData {
    std::string name;
    std::string textureFilename;
    Dimension frameSize;
    int framesPerRow;
    int framesPerCol;
    int initialHOffset;
    int initialVOffset;
    int hSpaceBetweenFrames;
    int vSpaceBetweenFrames;
};

/**
 * Sprite sheet data with texture data
 */
class SpriteSheet {
public:
    SpriteSheet(const SpriteSheetData& data, const Texture& texture);

    /**
     * Draws the frame located at index in the sprite sheet to the renderer at the given position
     * @param renderer target to render to
     * @param index frame index on sprite sheet (read from top-left to bottom-right)
     * @param position coordinates to draw to
     */
    void draw(const Renderer& renderer, const int index, const Vector2& position);

    /**
     * Returns the coordinates and size of the frame at the given index
     */
    Rect operator[](const int index);

    /**
     * Returns the sprite sheet's unique name
     */
    const std::string& getName() const;

private:
    const SpriteSheetData data;
    const Texture& texture;
};


#endif //FLAZARD_SPRITESHEET_H
