/**
 * @file ActiveFormat.hpp
 * @brief Declaration of the ActiveFormat class, which manages the active formatter for string formatting.
 * @details This class is a singleton that allows setting and getting formatted strings using different formatter types.
 */

#pragma once
#include "CenterFormatter.hpp"
#include "DirectFormatter.hpp"
#include "WrapFormatter.hpp"

/**
 * @class ActiveFormatter
 * @brief A class to manage the active formatter for string formatting.
 */
class ActiveFormatter {

 public:

    ActiveFormatter();
    ~ActiveFormatter();

    void setFormatter(string formatterType);
    string getActiveFormatterType();
    string getFormattedString(string input, int formatPoint);

 private:
    Formatter* formatter;
};