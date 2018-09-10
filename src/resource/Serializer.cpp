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

#include "Serializer.h"

void Serializer::to_json(json& j, const InputMapping& mapping) {
    std::unique_ptr<json> inputActions = reverseInputMap(mapping.inputActionMap);
    std::unique_ptr<json> inputStates = reverseInputMap(mapping.inputStateMap);

    j[INPUT_ACTIONS] = *inputActions;
    j[INPUT_STATES] = *inputStates;
}

void Serializer::from_json(const json& j, InputMapping& mapping) {
    reverseJson(mapping.inputActionMap, j[INPUT_ACTIONS]);
    reverseJson(mapping.inputStateMap, j[INPUT_STATES]);
}

void Serializer::to_json(json &j, const Entity& entity) {
//    j["name"] = entity.name;
//    j["spriteAnimations"] = entity.spriteAnimations;
}

void Serializer::from_json(const json &j, Entity& entity) {

}





void to_json(json& j, const Rect& r) {
    j = json{
            {"x", r.x},
            {"y", r.y},
            {"w", r.w},
            {"h", r.h}
    };
}

void from_json(const json& j, Rect& r) {
    r.x = j.at("x").get<int>();
    r.y = j.at("y").get<int>();
    r.w = j.at("w").get<int>();
    r.h = j.at("h").get<int>();
}

void to_json(json& j, const Point& p) {
    j = json{
            {"x", p.x},
            {"y", p.y},
    };
}

void from_json(const json& j, Point& p) {
    p.x = j.at("x").get<int>();
    p.y = j.at("y").get<int>();
}

void to_json(json& j, const Dimension& d) {
    j = json{
            {"w", d.w},
            {"h", d.h},
    };
}

void from_json(const json& j, Dimension& d) {
    d.w = j.at("w").get<int>();
    d.h = j.at("h").get<int>();
}

void to_json(json& j, const Vector2& v) {
    j = json{
            {"x", v.x},
            {"y", v.y},
    };
}

void from_json(const json& j, Vector2& v) {
    v.x = j.at("x").get<int>();
    v.y = j.at("y").get<int>();
}

void to_json(json& j, const InputMapping& mapping) {
    Serializer::to_json(j, mapping);
}

void from_json(const json& j, InputMapping& mapping) {
    Serializer::from_json(j, mapping);
}

void to_json(json& j, const SpriteSheetData& s) {
    j = json{
            {"name", s.name},
            {"textureFilename", s.textureFilename},
            {"frameSize", s.frameSize},
            {"framesPerRow", s.framesPerRow},
            {"framesPerCol", s.framesPerCol},
            {"initialHOffset", s.initialHOffset},
            {"initialVOffset", s.initialVOffset},
            {"hSpaceBetweenFrames", s.hSpaceBetweenFrames},
            {"vSpaceBetweenFrames", s.vSpaceBetweenFrames}
    };
}

void from_json(const json& j, SpriteSheetData& s) {
    s.name = j.at("name").get<std::string>();
    s.textureFilename = j.at("textureFilename").get<std::string>();
    s.frameSize = j.at("frameSize").get<Dimension>();
    s.framesPerRow = j.at("framesPerRow").get<int>();
    s.framesPerCol = j.at("framesPerCol").get<int>();
    s.initialHOffset = j.at("initialHOffset").get<int>();
    s.initialVOffset = j.at("initialVOffset").get<int>();
    s.hSpaceBetweenFrames = j.at("hSpaceBetweenFrames").get<int>();
    s.vSpaceBetweenFrames = j.at("vSpaceBetweenFrames").get<int>();

}

void to_json(json& j, const AnimationData& a) {
    j = json{
            {"name", a.name},
            {"spriteSheetName", a.spriteSheetName},
            {"frames", a.frames},
            {"pausableFrames", a.pausableFrames},
            {"loop", a.loop},
            {"frameDuration", a.frameDuration},
            {"frameDurationOverrides", a.frameDurationOverrides}
    };
}

void from_json(const json& j, AnimationData& a) {
    a.name = j.at("name").get<std::string>();
    a.spriteSheetName = j.at("spriteSheetName").get<std::string>();
    a.frames = j.at("frames").get<std::vector<unsigned>>();
    a.pausableFrames = j.at("pausableFrames").get<std::vector<bool>>();
    a.loop = j.at("loop").get<bool>();
    a.frameDuration = j.at("frameDuration").get<unsigned>();
    a.frameDurationOverrides = j.at("frameDurationOverrides").get<std::vector<unsigned>>();
}

void to_json(json& j, const Entity& entity) {
    Serializer::to_json(j, entity);
}

void from_json(const json& j, Entity& entity) {
    Serializer::from_json(j, entity);
}