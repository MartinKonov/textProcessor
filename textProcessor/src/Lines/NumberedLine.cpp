#include "../headers/Lines/NumberedLine.hpp"



/**
 * @brief If a line starts with <didgits>. it must never move during sorting
 * 
 */
bool NumberedLine::isMovableInSort() const
{
    return true;
}