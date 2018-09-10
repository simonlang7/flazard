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

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <SDL.h>
#include "resource_util.h"

#include "../drawing/Texture.h"
#include "../drawing/Renderer.h"
#include "../utility/Logger.h"

std::string getResourcePath(std::string subDir) {
    // Make sure path ends with /
    if (subDir.back() != '/')
        subDir += "/";

#ifdef _WIN32
    // If we're on Windows, replace path separator
    subDir = replaceAll(subDir, "/", "\\");
    char const PATH_SEP = '\\';
#else
    char const PATH_SEP = '/';
#endif

    // Directory where the game was executed
    static std::string baseDir;
    if (baseDir.empty()) {
        char *basePath = SDL_GetBasePath();
        if (basePath) {
            baseDir = basePath;
            SDL_free(basePath);
        }
        else {
            error("Error getting resource path: %s", SDL_GetError());
        }
    }

    return baseDir + ".." + PATH_SEP + "res" + PATH_SEP + subDir;
}

std::string replaceAll(std::string str, const char* toReplace, const char* replaceBy) {
    size_t index = 0;
    size_t originalLength = strlen(toReplace);
    size_t replacementLength = strlen(replaceBy);

    if (originalLength == 0) {
        std::ostringstream message;
        message << "Replacing substring failed (toReplace is empty)." << std::endl;
        message << "\tstr: " << str << std::endl;
        message << "\ttoReplace: " << toReplace << std::endl;
        message << "\treplaceBy: " << replaceBy << std::endl;
        Logger::get(LOG_LEVEL_WARNING) << message.str();
        return str;
    }

    while (true) {
        index = str.find(toReplace, index);
        if (index == std::string::npos)
            break;
        str.replace(index, originalLength, replaceBy);
        index += replacementLength;
    }

    return str;
}

/**
 * Only use this after cleaning up any loaded data.
 * Use error(...) instead to automatically handle clean up.
 * @param failure Exit code
 */
void exitWithFailure(int failure) {
    Logger::destroy();
    exit(failure);
}
