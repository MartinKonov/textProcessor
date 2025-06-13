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
    this->formatter = new DirectFormatter();
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
void ActiveFormatter::setFormatter(string formatterType) {
    if (formatter->getType() == formatterType) {
        return;
    }
    
    if (formatter) {
        delete formatter;
    }

    if (formatterType == "CenterFormatter") {
        formatter = new CenterFormatter();
    } else if (formatterType == "WrapFormatter") {
        formatter = new WrapFormatter();
    } else if (formatterType == "DirectFormatter") {
        formatter = new DirectFormatter();
    } else {
        throw std::runtime_error("ActiveFormatter::setFormatter: Unknown formatter type");
    }
}

/**
 * @brief Gets the formatted string based on the current formatter and input.
 * 
 * @param input The input string to format.
 * @param formatPoint The point at which to format the string (e.g., width for centering).
 * @return The formatted string.
 */
string ActiveFormatter::getFormattedString(string input, int formatPoint) {
    return formatter->format(input, formatPoint);
}