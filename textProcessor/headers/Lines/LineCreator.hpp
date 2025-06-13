/**
 * @file LineCreator.hpp
 * @author MK
 * @brief A singleton class to create Line objects based on the content of the line.
 * @version 0.1
 * @date 2025-05-18
 */


#pragma once
#include "Line.hpp"
#include "DefaultLine.hpp"
#include "NumberedLine.hpp"
#include "QuotedLine.hpp"
#include "NumericLine.hpp"


/**
 * @brief A singleton class to create Line objects based on the content of the line.
 */
class LineCreator 
{
 public:
 static LineCreator* getInstance();
 static void destroyInstance();
 Line* createLine(const string content);
   
 private:
      LineCreator(const LineCreator&) = delete;
      LineCreator& operator=(const LineCreator&) = delete;
      static LineCreator* lineCreator_;
      ~LineCreator() = default;
      LineCreator() = default;

    bool isNumberedLine(const string& content);
    bool isNumericLine(const string& content);
    bool isQuotedLine(const string& content);

};