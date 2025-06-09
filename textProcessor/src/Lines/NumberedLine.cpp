/**
 * @file NumberedLine.cpp
 * @author MK
 * @version 0.1
 * @date 2025-05-18
 */

#include "../../headers/Lines/NumberedLine.hpp"



/**
 * @brief If a line starts with <didgits>. it must never move during sorting
 * 
 */
bool NumberedLine::isMovableInSort() const {
    return false;
}