/**
 * @file CenterFormatter.hpp
 * @brief Declaration of the CenterFormatter class, which formats strings by centering them within a specified width.
 * @details This class inherits from the Formatter base class and implements the format method to center text based on a given wrap point.
 */

#pragma once
#include "Formatter.hpp"


/**
 * @class CenterFormatter
 * @brief A class to format strings by centering them within a specified width.
 */
class CenterFormatter : public Formatter {
 public:
    CenterFormatter() = default;
    ~CenterFormatter() = default;

    string format(string input, int formatPoint) override;
    string getType() override;

 private:

    string centerText(const string& text, int width);
};