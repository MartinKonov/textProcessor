/**
 * @file NumericLine.cpp
 * @author MK
 * @brief A class to represent a line that is purely a number.
 * @version 0.1
 * @date 2025-05-18
 */
#include "../../headers/Lines/NumericLine.hpp"



/**
 * @brief If a line is purely a number (e.g. “  42  ”), compare by numeric value
 * 
 */
//  * @param other The other line to compare with
//  * @return true if this line is less than the other line
//  * @return false otherwise
bool NumericLine::operator< (const Line& other) const 
{
   long long myValue = atol(trimmedContent().c_str());
    long long otherValue = atol(((NumericLine&)other).trimmedContent().c_str()); 

    return myValue < otherValue;
}

/**
 * @brief Trims the line from both sides
 *
 * @return string The trimmed content of the line
 */
string NumericLine::trimmedContent() const 
{
    size_t start = content.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = content.find_last_not_of(" \t\r\n");
    return content.substr(start, end - start + 1);
}