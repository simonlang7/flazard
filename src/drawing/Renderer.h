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

#ifndef FLAZARD_RENDERBACKEND_H
#define FLAZARD_RENDERBACKEND_H

#include <string>
#include <unordered_map>
#include <memory>
#include <SDL.h>
#include "Texture.h"

class Renderer {
public:
    /**
     * Initialize the renderer with the given parameters
     * @param hRes  Horizontal resolution
     * @param vRes  Vertical resolution
     */
    Renderer(int hRes, int vRes);

    /**
     * Destroy the renderer and all associated objects
     */
    ~Renderer();

    /**
     * Initialize drawing process (call this each frame before drawing)
     */
    void clear();

    /**
     * Draw an element on the screen
     * @param texture   Texture to draw
     * @param source    Part of the texture to draw
     * @param position  Where to draw the texture
     * @param size      Size to scale the element to
     */
    void draw(const Texture& texture, const Rect& source,
              const Vector2& position, const Dimension& size) const;

    /**
     * Draw an element on the screen
     * @param texture   Texture to draw
     * @param source    Part of the texture to draw
     * @param position  Where to draw the texture
     */
    void draw(const Texture& texture, const Rect& source, const Vector2& position) const;

    /**
     * Draw an element on the screen
     * @param texture   Texture to draw
     * @param position  Where to draw the texture
     */
    void draw(const Texture& texture, const Vector2& position) const;

    /**
     * Finish drawing process (present drawn elements to the screen)
     */
    void present();

    /**
     * Load a texture from the given path with the given filename
     * @return Unique texture identifier
     */
    const Texture& loadTexture(const std::string path, const std::string filename);

    /**
     * Load a texture from the path including the filename
     * @return Unique texture identifier
     */
    const Texture& loadTexture(const std::string fullFilename);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::unordered_map<std::string, std::unique_ptr<Texture>> textures;
};


#endif //FLAZARD_RENDERBACKEND_H
