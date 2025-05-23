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

 private:
    string trimmedContent() const;

};