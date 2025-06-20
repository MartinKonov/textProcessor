/**
 * @file WrapFormatter.cpp
 * @author MK
 * @brief A formatter that wraps text at a specified point.
 */
#include "../../headers/Formatter/WrapFormatter.hpp"

WrapFormatter::WrapFormatter(int formatPoint) : Formatter(formatPoint) {}

/**
 * @brief Returns the type of this formatter.
 * @return A string indicating the type of formatter.
 */
string WrapFormatter::getType() {
    return FORMATTER_TYPE_WRAP;
}

int WrapFormatter::getFormatPoint() {
    return formatPoint;
}

/**
 * @brief Formats the input string by wrapping it at a specified point.
 * @param input The input string to format.
 * @param formatPoint The point at which to wrap the text.
 * @return The formatted string with wrapped text.
 * @throws std::runtime_error if formatPoint is less than or equal to 0.
 */
string WrapFormatter::format(string input) {
    string baseString = removeNewLines(input);
    string result;

    for(int i = 0; i< baseString.length(); i += formatPoint) {
        if (i + formatPoint < baseString.length()) {
            result += baseString.substr(i, formatPoint) + '\n';
        } else {
            result += baseString.substr(i);
        }
    }
    return result;
}
