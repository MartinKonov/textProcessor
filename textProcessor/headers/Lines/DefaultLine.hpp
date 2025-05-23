/**
 * @file DefaultLine.hpp
 * @author MK
 * @brief 
 * @version 0.1
 * @date 2025-05-18
 */

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