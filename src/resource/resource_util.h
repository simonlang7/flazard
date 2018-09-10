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

#ifndef FLAZARD_RESOURCE_HELPER_H
#define FLAZARD_RESOURCE_HELPER_H

#include <iostream>
#include <string>
#include <utility>
#include <SDL.h>
#include "../utility/ErrorContext.h"
#include "../utility/Logger.h"
#include "../utility/types.h"

#define DEVELOPMENT

#if defined(DEVELOPMENT)
    /**
     * Checks whether the given test is true, and prints an error if not
     */
    #define XASSERT(test, msg, ...) do {if (!(test)) assertError(__FILE__, __LINE__, \
        "Assertion failed", #test, msg, __VA_ARGS__);} while (0)
#else
    #define XASSERT(test, msg, ...) ((void)0)
#endif


/**
 * Returns the full path of the "res/" directory including the requested sub-directory
 */
std::string getResourcePath(std::string subDir);

/**
 * Replaces all occurrences of toReplace by replaceBy within the given string str
 */
std::string replaceAll(std::string str, const char* toReplace, const char* replaceBy);

/**
 * Exit immediately with the given failure code
 */
void exitWithFailure(int failure);

/**
 * Basic error function, prints error, destroys the render backend
 * and exits the program with failure code 1
 * @param message   Error message to print
 * @param args      Parameters for message (as in printf)
 */
template<typename... Args>
void error(const char* message, Args... args) {
    std::ostream& logger = Logger::get(LOG_LEVEL_ERROR);

    // Print custom error message
    // TODO: Get rid of snprintf shit
    size_t messageLength = strlen(message) * 5;
    auto* buffer = new char[messageLength];
    snprintf(buffer, messageLength, message, args...);
    logger << buffer << std::endl;
    delete[](buffer);

    // Show error context
    if (!ErrorContext::errorContextName.empty()) {
        logger << std::endl << "\tError context: " << std::endl;
        auto itName = ErrorContext::errorContextName.begin();
        auto itData = ErrorContext::errorContextData.begin();
        for (;
                itName != ErrorContext::errorContextName.end()
                && itData != ErrorContext::errorContextData.end();
                ++itName, ++itData) {
            logger << "\t\t" << (*itName);
            if (strlen(*itData) > 0)
                logger << ": " << (*itData);
            logger << std::endl;
        }
    }

    logger << std::endl;

    // Allow game loop to properly clean up
    throw FatalError();
}

/**
 * Extended error function, used by XASSERT
 */
template<typename... Args>
void assertError(const char* file, int line, const char* type, const char* term,
           const char* message, Args... args) {
    std::ostream& logger = Logger::get(LOG_LEVEL_ERROR);
    // Print file and line
    logger << "Error in " << file << ":" << line << ": " << type;
    if (term && *term)
        logger << ": " << term;
    logger << std::endl << "\t";

    error(message, args...);
}

/**
 * Clean up SDL resources
 * @tparam T SDL resource type
 * @tparam Args Further argument types
 * @param t SDL resource to clean up
 * @param args Further resources to clean up
 */
template<typename T, typename... Args>
void cleanUp(T* t, Args&&... args){
    // Clean up the first resource
    cleanUp(t);
    // Clean up others
    cleanUp(std::forward<Args>(args)...);
}

/**
 * Clean up SDL_Window
 */
template<>
inline void cleanUp<SDL_Window>(SDL_Window* win){
    if (!win){
        return;
    }
    SDL_DestroyWindow(win);
}

/**
 * Clean up SDL_Renderer
 */
template<>
inline void cleanUp<SDL_Renderer>(SDL_Renderer* ren){
    if (!ren){
        return;
    }
    SDL_DestroyRenderer(ren);
}

/**
 * Clean up SDL_Texture
 */
template<>
inline void cleanUp<SDL_Texture>(SDL_Texture* tex){
    if (!tex){
        return;
    }
    SDL_DestroyTexture(tex);
}

/**
 * Clean up SDL_Surface
 */
template<>
inline void cleanUp<SDL_Surface>(SDL_Surface* surf){
    if (!surf){
        return;
    }
    SDL_FreeSurface(surf);
}

#endif //FLAZARD_RESOURCE_HELPER_H
