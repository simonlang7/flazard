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

#ifndef FLAZARD_TEXTURE_H
#define FLAZARD_TEXTURE_H

#include <SDL.h>
#include "../resource/resource_util.h"
#include "../utility/types.h"

/**
 * Simple texture wrapper class for SDL textures
 */
class Texture {
public:
    explicit Texture(SDL_Texture* texture);
    ~Texture();

    SDL_Texture* const getTexture() const;
    const Dimension& getSize() const;

private:
    SDL_Texture* const texture;
    Dimension size;
};


#endif //FLAZARD_TEXTURE_H
