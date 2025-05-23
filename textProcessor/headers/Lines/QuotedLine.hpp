#pragma once
#include "Line.hpp"


/**
 * @brief If a line is enclosed in double quotes (possibly with leading/trailing spaces
        outside the quotes), then (a) do NOT apply trim inside the quotes, and (b) do
        NOT change case inside the quotes.  Case‐changing/trim only applies outside.
 * 
 */
class QuotedLine : public Line{
 public:
    QuotedLine(const std::string& text) : Line(text) {}
    void trim() override;
    void toUpper() override;
    void toLower() override;

 private:
    size_t findFirstQuote();
    size_t findLastQuote(size_t firstQuote);
};