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

#ifndef FLAZARD_LOGGER_H
#define FLAZARD_LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

#define LOG_TO_CONSOLE 1
#define LOG_TO_FILE 2
#define LOG_TO_SCREEN 4

#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_VERBOSE 4
#define LOG_LEVEL_DEBUG 5
#define LOG_LEVEL_ALL 255

#define DEFAULT_LOG_TO LOG_TO_CONSOLE
#define DEFAULT_LOG_LEVEL LOG_LEVEL_ALL

/**
 * Basic logger that can send messages to different streams (stdout, a file,
 * the screen)
 */
class Logger {
public:
    static void init(const std::string& logFilename = "flazard.log");
    static void destroy();

    static std::ostream& get(unsigned int logTo, unsigned int logLevel);
    static std::ostream& get(unsigned int logLevel);

private:
    static std::ofstream* logFile;
};


#endif //FLAZARD_LOGGER_H
