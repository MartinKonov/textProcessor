#include "../../headers/Formatter/DirectFormatter.hpp"

/**
 * @brief Formats the input string by returning it as is.
 * @param input The input string to format.
 * @return The input string unchanged.
 */
string DirectFormatter::format(string input, int formatPoint) {
    return input;
}

/**
 * @brief Returns the type of this formatter.
 * @return A string indicating the type of formatter.
 */
string DirectFormatter::getType() {
    return "DirectFormatter";
}
