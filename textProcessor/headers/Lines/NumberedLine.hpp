#include "Line.hpp"

/**
 * @brief If a line starts with <didgits>. it must never move during sorting
 * 
 */
class NumberedLine : public Line {
 public:
    NumberedLine(const string text) : Line(text) {}

    bool isMovableInSort() const override;
};