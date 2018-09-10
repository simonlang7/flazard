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

#ifndef FLAZARD_ERRORCONTEXT_H
#define FLAZARD_ERRORCONTEXT_H

#include <vector>

/**
 * Keeps stack of function names and working data for further inspection when
 * the application crashes or another error occurs.
 * Any function that might encounter errors can (and should) initialize an
 * ErrorContext on its stack, to be destroyed when the function exits.
 */
class ErrorContext {
public:
    thread_local static std::vector<const char*> errorContextName;
    thread_local static std::vector<const char*> errorContextData;

    ErrorContext(const char* name, const char* data);
    ~ErrorContext();
};


#endif //FLAZARD_ERRORCONTEXT_H
