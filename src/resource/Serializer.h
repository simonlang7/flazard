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

#ifndef FLAZARD_SERIALIZER_H
#define FLAZARD_SERIALIZER_H

#include "../include/json.hpp"
#include "../input/mapping/InputMapping.h"
#include "../drawing/SpriteSheet.h"
#include "../drawing/SpriteAnimation.h"
#include "../game/Entity.h"

using nlohmann::json;

class ResourceManager;

/**
 * Handles serialization of all game-specific types.
 * Define it as a friend to have it access private members.
 */
class Serializer {
public:
    static void to_json(json& j, const InputMapping& mapping);
    static void from_json(const json& j, InputMapping& mapping);
    static void to_json(json& j, const Entity& entity);
    static void from_json(const json& j, Entity& entity);

private:

    /// Reverses a given map (k -> v) and returns a json that represents a map (v -> list of k)
    /// \tparam T Input type used as the map's key
    /// \param inputMap Map to convert
    /// \return Reversed map as a json that contains the former values as keys, and former keys as a list of values
    template<typename T>
    static std::unique_ptr<json> reverseInputMap(const std::unordered_map<SDL_Keycode, T>& inputMap) {
        std::unique_ptr<json> result = std::make_unique<json>();

        std::unordered_map<T, std::list<SDL_Keycode>> reverseActionMap;
        for (auto it = inputMap.cbegin(); it != inputMap.cend(); ++it) {
            reverseActionMap[it->second].emplace_back(it->first);
        }
        int i = 0;
        for (auto it = reverseActionMap.cbegin(); it != reverseActionMap.cend(); ++it) {
            (*result)[i++] = { { INPUT, it->first }, { KEYS, it->second } };
        }

        return result;
    }

    template<typename T>
    static void reverseJson(std::unordered_map<SDL_Keycode, T>& result, const json& reverseInputMap) {
        for (const auto& it : reverseInputMap) {
            //json& keys = ;
            for (auto it2 = it[KEYS].cbegin(); it2 != it[KEYS].cend(); ++it2) {
                result[*it2] = it[INPUT];
            }
        }
    };
};


// types.h
void to_json(json& j, const Rect& r);
void from_json(const json& j, Rect& r);
void to_json(json& j, const Point& p);
void from_json(const json& j, Point& p);
void to_json(json& j, const Dimension& d);
void from_json(const json& j, Dimension& d);
void to_json(json& j, const Vector2& v);
void from_json(const json& j, Vector2& v);

void to_json(json& j, const InputMapping& mapping);
void from_json(const json& j, InputMapping& mapping);

void to_json(json& j, const SpriteSheetData& s);
void from_json(const json& j, SpriteSheetData& s);

void to_json(json& j, const AnimationData& a);
void from_json(const json& j, AnimationData& a);

void to_json(json& j, const Entity& entity);
void from_json(const json& j, Entity& entity);

#endif //FLAZARD_SERIALIZER_H
