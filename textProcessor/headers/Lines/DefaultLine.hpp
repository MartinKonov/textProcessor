#pragma once
#include "Line.hpp"


/**
 * @brief Any line that doesn’t match the other three special cases: “normal” behavior.
 * 
 */
class DefaultLine : public Line {
 public:
    DefaultLine(const std::string& text) : Line(text) {}
};