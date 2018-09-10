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

#ifndef FLAZARD_COLLECTION_HELPER_H
#define FLAZARD_COLLECTION_HELPER_H

#include <algorithm>

template<typename Collection, typename UnaryOp>
void foreach(Collection& col, UnaryOp& op) {
    std::for_each(col.begin(), col.end(), op);
}

template<typename Collection, typename Elem>
bool remove(Collection& col, Elem element) {
    for (auto it = col.begin(); it != col.end(); ++it) {
        if (*it == element) {
            col.erase(it);
            return true;
        }
    }
    return false;
}

template<typename Collection, typename Elem>
bool removeAll(Collection& col, Elem element) {
    bool erased = false;
    for (auto it = col.begin(); it != col.end(); ++it) {
        while (*it == element) {
            it = col.erase(it);
            erased = true;
        }
    }
    return erased;
}

template<typename Collection, typename Check>
bool contains(Collection& col, Check& check) {
    for (auto item : col) {
        if (check(item))
            return true;
    }
    return false;
}

#endif //FLAZARD_COLLECTION_HELPER_H
