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

#include "ErrorContext.h"

ErrorContext::ErrorContext(const char* name, const char* data) {
    errorContextName.push_back(name);
    errorContextData.push_back(data);
}

ErrorContext::~ErrorContext() {
    errorContextName.pop_back();
    errorContextData.pop_back();
}

thread_local std::vector<const char*> ErrorContext::errorContextName;
thread_local std::vector<const char*> ErrorContext::errorContextData;