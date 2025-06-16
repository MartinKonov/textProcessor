/**
 * @file ActiveFormatter.cpp
 * @author MK
 * @brief A class to manage the active formatter in the text processor application.
 */
#include "../../headers/Formatter/ActiveFormatter.hpp"


/**
 * @brief Constructor for the ActiveFormatter class.
 */
ActiveFormatter::ActiveFormatter() {
    formatPoint = 0;
    this->formatter = new DirectFormatter(0);
}

/**
 * @brief Destructor for the ActiveFormatter class.
 * It deletes the current formatter to free up memory.
 */
ActiveFormatter::~ActiveFormatter() {
    delete formatter;
}

/**
 * @brief Sets the formatter type for the ActiveFormatter.
 * 
 * @param formatterType The type of formatter to set (e.g., "CenterFormatter", "WrapFormatter", "DirectFormatter").
 * @throws runtime_error if the formatter type is unknown.
 */
void ActiveFormatter::setFormatter(string formatterType, int formatPoint) {
    if (formatterType != FORMATTER_TYPE_CENTER && formatterType != FORMATTER_TYPE_WRAP && formatterType != FORMATTER_TYPE_DIRECT) {
        throw runtime_error(ERROR_INVALID_FORMATTER_TYPE);
    }

    if (formatter && formatter->getType() == formatterType) {
        return;
    }

    delete formatter;

    if (formatterType == FORMATTER_TYPE_CENTER) {
        formatter = new CenterFormatter(formatPoint);
        this->formatPoint = formatPoint;
    } else if (formatterType == FORMATTER_TYPE_WRAP) {
        formatter = new WrapFormatter(formatPoint);
        this->formatPoint = formatPoint;
    } else if (formatterType == FORMATTER_TYPE_DIRECT) {
        formatter = new DirectFormatter(formatPoint);
        this->formatPoint = 0;
    }
}

string ActiveFormatter::getActiveFormatterType() {
    return formatter->getType();
}

int ActiveFormatter::getActiveFormatterFormatPoint() {
    return  formatter->getFormatPoint();
}

/**
 * @brief Gets the formatted string based on the current formatter and input.
 * 
 * @param input The input string to format.
 * @param formatPoint The point at which to format the string (e.g., width for centering).
 * @return The formatted string.
 */
string ActiveFormatter::getFormattedString(string input) {
    return formatter->format(input);
}