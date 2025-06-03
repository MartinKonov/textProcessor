/**
 * @file Line.cpp
 * @author MK
 * @brief A singleton class to create Line objects based on the content of the line.
 * @version 0.1
 * @date 2025-05-18
 */


#include "../../headers/Lines/Line.hpp"


Line::Line(Line& other) {
    this->content = other.content;
}

Line& Line::operator=(Line& other) {
    if(this != &other)
    {
        this->content = other.content;
    }

    return *this;
}

/**
 * @brief Returns the content of the line
 *
 * @return string The content of the line
 */
string Line::getLine() {
    return content;
}

/**
 * @brief Returns the number of symbols in the line
 *
 * @return size_t The number of symbols in the line
 */
size_t Line::getSymbolCount() 
{
    return content.size();
}

/**
 * @brief Checks if the line contains a substring
 *
 * @param searched The substring to search for
 * @return true if the substring is found
 * @return false otherwise
 */
bool Line::contains(const string searched) 
{
    return content.find(searched) != string::npos;
}

/**
 * @brief Replaces a substring in the line with another string
 *
 * @param target The substring to be replaced
 * @param replacement The string to replace with
 * @throws std::invalid_argument if the target substring is not found
 */
void Line::replace(const string target, const string replacement) 
{
    if (!contains(target)) {
        throw std::invalid_argument("Line::replace: substring '" + target 
            + "' not found in \"" + content + "\"");
    }

    size_t pos = content.find(target, pos);
    content.replace(pos, target.length(), replacement);
}

/**
 * @brief Converts the line to upper case
 *
 */
void Line::toUpper() 
{
    for (char &c : content) {
        c = upper(c);
    }
}

/**
 * @brief Converts the line to lower case
 *
 */
void Line::toLower() 
{
    for (char &c : content) {
        c = lower(c);
    }
}

/**
 * @brief Checks if the line is movable in sort
 *
 * @return true if the line is movable in sort
 * @return false otherwise
 */
bool Line::isMovableInSort() const 
{
    return true;
}


/**
 * @brief Compares two lines for sorting
 *
 * @param other The other line to compare with
 * @return true if this line is less than the other line
 * @return false otherwise
 */
bool Line::operator<(const Line &other) const 
{
    return content < other.content;
}
/**
 * @brief Trims the line from both sides
 *
 */
void Line::trim() 
{ 
    trimLeading();
    trimTrailing();
}

/**
 * @brief Trims the line from the left side
 *
 */
void Line::trimLeading()
{
    size_t start = content.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) 
    {
        content.clear();
    } 
    else
    {
        content = content.substr(start);
    }
}

/**
 * @brief Trims the line from the right side
 *
 */
void Line::trimTrailing()
{    
    size_t end = content.find_last_not_of(" \t\r\n");
    if (end == std::string::npos) 
    {
        content.clear();
    } else 
    {
        content = content.substr(0, end + 1);
    }
}

/**
 * @brief Converts a character to lower case
 *
 * @param c The character to convert
 * @return char The converted character
 */
char Line::lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
} 
 
 /**
  * @brief Converts a character to upper case
  *
  * @param c The character to convert
  * @return char The converted character
  */
 char Line::upper(int c)
 {
     if (c >= 'a' && c <= 'z') {
         return c - ('a' - 'A');
     }
     return c;
 }