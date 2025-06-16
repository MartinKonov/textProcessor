/**
 * @file Formatter.hpp
 * @brief Declaration of the Formatter base class.
 * @details This class serves as an interface for different string formatting implementations.
 */
#pragma once
#include <string>
#include <stdexcept>
#include <vector>
#include "../../dataFiles/CommonErrors.hpp"
#include "../../dataFiles/FormatterTypes.hpp"

using std::string;
using std::vector;

/**
 * @class Formatter
 * @brief An abstract base class for string formatting.
 * @details This class defines the interface for formatting strings, including methods for formatting and retrieving the type of formatter.
 */
class Formatter {
 public:
    explicit Formatter(int formatPoint) : formatPoint(formatPoint) {}
    virtual string format(string input) = 0;
    virtual string getType() = 0;
    virtual int getFormatPoint() = 0;
    virtual ~Formatter() = default;

 protected:
    string removeNewLines(const string& input);
    vector<string> split(const string& str, char delimiter);
    int formatPoint;
};