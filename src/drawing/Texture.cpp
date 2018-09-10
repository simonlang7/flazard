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

#include "Texture.h"

Texture::Texture(SDL_Texture* texture) : texture(texture) {
    // Get size
    SDL_QueryTexture(texture, nullptr, nullptr, &size.w, &size.h);
}

Texture::~Texture() {
    cleanUp(texture);
}

SDL_Texture* const Texture::getTexture() const {
    return texture;
}

const Dimension& Texture::getSize() const {
    return size;
}
