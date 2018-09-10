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

#include <ctime>
#include <chrono>
#include "Logger.h"
#include "../resource/resource_util.h"

std::ofstream* Logger::logFile = nullptr;

void Logger::init(const std::string& logFilename) {
    Logger::logFile = new std::ofstream(logFilename, std::ofstream::out | std::ofstream::app);

    // Create timestamp
    using clock = std::chrono::system_clock;
    std::time_t now = clock::to_time_t(clock::now());
    Logger::get(LOG_LEVEL_ALL) << std::endl << std::endl
                               << "Log session start at "
                               << std::ctime(&now) << std::endl;
}

void Logger::destroy() {
//    Logger::logFile->flush();
    Logger::logFile->close();
    delete(Logger::logFile);
}

std::ostream& Logger::get(unsigned int logTo, unsigned int logLevel) {
    // TODO: return /dev/null-like stream
    //if (DEFAULT_LOG_LEVEL < logLevel)


    switch (logTo) {
        case LOG_TO_CONSOLE:
#ifdef _WIN32
            return *Logger::logFile;
#else
            return std::cout;
#endif
        case LOG_TO_FILE:
            return *Logger::logFile;
        default:
            std::cout << "Failed to find logger of type " << logTo << std::endl;
            std::cout << "Logging to std::cout" << std::endl;
            return std::cout;
    }
}

std::ostream& Logger::get(unsigned int logLevel) {
    return Logger::get(DEFAULT_LOG_TO, logLevel);
}
