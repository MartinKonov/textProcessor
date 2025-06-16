/**
 * @file DirectFormatter.cpp
 * @author MK
 * @brief A class that formats input strings directly without any modifications.
 */
#include "../../headers/Formatter/DirectFormatter.hpp"

DirectFormatter::DirectFormatter(int formatPoint) : Formatter(formatPoint) {}


/**
 * @brief Formats the input string by returning it as is.
 * @param input The input string to format.
 * @return The input string unchanged.
 */
string DirectFormatter::format(string input) {
    return input;
}

int DirectFormatter::getFormatPoint() {
    return 0;
}

/**
 * @brief Returns the type of this formatter.
 * @return A string indicating the type of formatter.
 */
string DirectFormatter::getType() {
    return FORMATTER_TYPE_DIRECT;
}
