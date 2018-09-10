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

#ifndef FLAZARD_RESOURCEMANAGER_H
#define FLAZARD_RESOURCEMANAGER_H

#include "Serializer.h"

class ResourceManager {
public:
    /**
     * Loads resource from a JSON file
     * @tparam T Resource type to load
     * @param path Path to JSON file
     * @param filename JSON filename
     * @return Unique pointer to the loaded resource
     */
    template<typename T>
    static std::unique_ptr<T> load(const std::string& path, const std::string& filename) {
        return load<T>(path + filename);
    }

    /**
     * Loads resource from a JSON file
     * @tparam T Resource type to load
     * @param fullFilename full path to JSON
     * @return Unique pointer to the loaded resource
     */
    template<typename T>
    static std::unique_ptr<T> load(const std::string& fullFilename) {
        ErrorContext errorContext("In ResourceManager::load", fullFilename.c_str());

        std::ifstream file(fullFilename);
        json json;

        // TODO: No pokemon exception handling?
        try {
            file >> json;
        } catch (...) {
            error("Error loading file.");
        }
        std::unique_ptr<T> result = std::make_unique<T>(json);
        return result;
    }
};


#endif //FLAZARD_RESOURCEMANAGER_H
