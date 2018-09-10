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

#include "ScreenManager.h"
#include <utility>
#include "../resource/resource_util.h"

ScreenManager::ScreenManager(std::shared_ptr<Renderer> renderer) :
    renderer(std::move(renderer)) {
}

ScreenManager::~ScreenManager() = default;


void ScreenManager::handleInput(const PlayerActions& actions, const PlayerStates& states) {
    screens.back()->handleInput(actions, states);
}

void ScreenManager::update(double elapsedTime) {
    screens.back()->update(elapsedTime);
}

void ScreenManager::draw() {
    renderer->clear();
    screens.back()->draw(*renderer);
    renderer->present();
}

void ScreenManager::pushScreen(std::shared_ptr<Screen> screen) {
    screens.push_back(screen);
}

void ScreenManager::popScreen() {
    XASSERT(screens.empty(), "screens is already empty.", "");
    screens.pop_back();
}

void ScreenManager::clear() {
    screens.clear();
}

unsigned ScreenManager::size() {
    return (unsigned)screens.size();
}
