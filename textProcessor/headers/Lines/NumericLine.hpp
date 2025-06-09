/**
 * @file NumericLine.hpp
 * @author MK
 * @brief
 * @version 0.1
 * @date 2025-05-18
 */
#pragma once
#include "Line.hpp"


/**
 * @brief  If a line is purely a number (e.g. “  42  ”), compare by numeric value
 * 
 */
class NumericLine : public Line {

 public:
    NumericLine(const string text) : Line(text){};
    bool operator< (const Line& other) const override;
    bool isNumericLine() const override;
    long long getNumericValue() const override;

 private:
    string trimmedContent() const;

};