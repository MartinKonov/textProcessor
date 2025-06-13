/**
 * @file WrapFormatter.cpp
 * @author MK
 * @brief A formatter that wraps text at a specified point.
 */
#include "../../headers/Formatter/WrapFormatter.hpp"

/**
 * @brief Returns the type of this formatter.
 * @return A string indicating the type of formatter.
 */
string WrapFormatter::getType() {
    return "WrapFormatter";
}

/**
 * @brief Formats the input string by wrapping it at a specified point.
 * @param input The input string to format.
 * @param formatPoint The point at which to wrap the text.
 * @return The formatted string with wrapped text.
 * @throws std::runtime_error if formatPoint is less than or equal to 0.
 */
string WrapFormatter::format(string input, int formatPoint) {
    if (formatPoint <= 0) {
        throw std::runtime_error("WrapFormatter::format: formatPoint must be greater than 0");
    }

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
