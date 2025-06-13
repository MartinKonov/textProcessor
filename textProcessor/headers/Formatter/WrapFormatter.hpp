/**
 * @file WrapFormatter.hpp
 * @brief Declaration of the WrapFormatter class, which formats strings by wrapping them at a specified point.
 * @details This class inherits from the Formatter base class and implements the format method to wrap text based on a given format point.
 */

#pragma once
#include "Formatter.hpp"

/**
 * @class WrapFormatter
 * @brief A class that formats strings by wrapping them at a specified point.
 */
class WrapFormatter : public Formatter {
 public:
    WrapFormatter() = default;
    ~WrapFormatter() = default;

    string format(string input, int formatPoint) override;
    string getType() override;

};
