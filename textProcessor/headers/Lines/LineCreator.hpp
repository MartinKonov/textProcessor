#pragma once
#include "Line.hpp"
#include "DefaultLine.hpp"
#include "NumberedLine.hpp"
#include "QuotedLine.hpp"
#include "NumericLine.hpp"


class LineCreator 
{
 public:
    LineCreator(const LineCreator&) = delete;
    LineCreator& operator=(const LineCreator&) = delete;
    static LineCreator* getInstance();
    Line* createLine(const string content);

 private:
    static LineCreator* lineCreator_;

    LineCreator() = default;

    bool isNumberedLine(const string& content);
    bool isNumericLine(const string& content);
    bool isQuotedLine(const string& content);

};