/**
 * @file DirectFormatter.hpp
 * @brief Declaration of the DirectFormatter class, which formats strings directly without modification.
 * @details This class inherits from the Formatter base class and implements the format method to return the input string unchanged.
 */

#pragma once
#include "Formatter.hpp"

/**
 * @class DirectFormatter
 * @brief A class to format strings directly without modification.
 */
class DirectFormatter : public Formatter {
 public:
    explicit DirectFormatter(int formatPoint);
    ~DirectFormatter() = default;

    int getFormatPoint() override;
    string format(string input) override;
    string getType() override;
};
