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

#include <SDL_image.h>
#include "Renderer.h"
#include "../utility/ErrorContext.h"
#include "../resource/resource_util.h"


Renderer::Renderer(int hRes, int vRes) {
    ErrorContext errorContext("When initializing render backend", "");

    // Init SDL and SDL_image
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        error("Failed to initialize SDL: %s", SDL_GetError());
    if (IMG_Init(IMG_INIT_PNG) == 0)
        error("Failed to initialize SDL_image: %s", IMG_GetError());

    // Create window ...
    window = SDL_CreateWindow("Flazard", 100, 100, hRes, vRes, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        error("Failed to create window: %s", SDL_GetError());

    // ... and renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
                                              | SDL_RENDERER_PRESENTVSYNC);

    // TODO: automatic scaling
    if (SDL_RenderSetScale(Renderer::renderer, 3, 3) != 0)
        error("Failed to set render scale: %s", SDL_GetError());

    if (renderer == nullptr)
        error("Failed to create renderer: %s", SDL_GetError());
}

Renderer::~Renderer() {
    Logger::get(LOG_LEVEL_DEBUG) << "Cleaning up renderer";
    textures.clear();
    cleanUp(renderer, window);
    IMG_Quit();
    SDL_Quit();
}

void Renderer::clear() {
    SDL_RenderClear(renderer);
}

void Renderer::draw(const Texture& texture, const Rect& source,
                    const Vector2& position, const Dimension& size) const {
    SDL_Rect src;
    src.x = source.x; src.y = source.y; src.w = source.w; src.h = source.h;
    SDL_Rect dst;
    dst.x = (int)position.x; dst.y = (int)position.y;
    dst.w = size.w; dst.h = size.h;
    SDL_RenderCopy(renderer, texture.getTexture(), &src, &dst);
}

void Renderer::draw(const Texture& texture, const Rect& source, const Vector2& position) const {
    SDL_Rect src;
    src.x = source.x; src.y = source.y; src.w = source.w; src.h = source.h;
    SDL_Rect dst;
    dst.x = (int)position.x; dst.y = (int)position.y;
    dst.w = src.w; dst.h = src.h;
    SDL_RenderCopy(renderer, texture.getTexture(), &src, &dst);
}

void Renderer::draw(const Texture& texture, const Vector2& position) const {
    SDL_Rect dst;
    dst.x = (int)position.x; dst.y = (int)position.y;
    dst.w = texture.getSize().w; dst.h = texture.getSize().h;
    SDL_RenderCopy(renderer, texture.getTexture(), nullptr, &dst);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

const Texture& Renderer::loadTexture(const std::string path, const std::string filename) {
    return loadTexture(path + filename);
}

const Texture& Renderer::loadTexture(const std::string fullFilename) {
    ErrorContext errorContext("When loading texture", fullFilename.c_str());

    // Texture already exists?
    if (textures.find(fullFilename) != textures.end())
        return *textures[fullFilename];
    else {
        // Load texture
        SDL_Texture *sdlTexture = IMG_LoadTexture(renderer, fullFilename.c_str());
        XASSERT(sdlTexture != nullptr, "Failed to load texture: %s", SDL_GetError());

        textures[fullFilename] = std::make_unique<Texture>(sdlTexture);

        return *textures[fullFilename];
    }
}
