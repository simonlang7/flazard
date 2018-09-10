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

#ifndef FLAZARD_INPUTACTION_H
#define FLAZARD_INPUTACTION_H

/**
 * One-off actions that are processed during a single frame
 */
enum InputAction {
    ACTION_NONE,
    ACTION_CURSOR_UP,
    ACTION_CURSOR_DOWN,
    ACTION_CURSOR_LEFT,
    ACTION_CURSOR_RIGHT,
    ACTION_OK,
    ACTION_CANCEL,
    ACTION_MENU,

    ACTION_QUIT,
    ACTION_COUNT
};

/**
 * Goes along with an InputAction and specifies whether it has been
 * pressed or released
 */
enum InputType {
    TYPE_NONE,
    TYPE_PRESS,
    TYPE_RELEASE,

    TYPE_COUNT
};

/**
 * InputStates are processed over a certain timespan
 */
enum InputState {
    STATE_NONE,
    STATE_WALK_UP,
    STATE_WALK_DOWN,
    STATE_WALK_LEFT,
    STATE_WALK_RIGHT,

    STATE_COUNT
};

#endif //FLAZARD_INPUTACTION_H
