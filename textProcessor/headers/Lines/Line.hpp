#pragma once
/**
 * @file Line.hpp
 * @author Martin Konov
 * @brief A class, defining a single line from a document
 * @version 0.1
 * @date 2025-05-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <string>
#include <stdexcept>

using std::string;

/**
 * @brief A class defining a single line from a document
 * 
 */
class Line {
    
 public:
    
    Line() = default;
    Line(const string text) : content(text) {};
    ~Line() = default;
    Line(Line& other);
    Line& operator=(Line& other);

    bool operator==(Line& other);
    bool operator!=(Line& other);

    virtual string getLine();
    virtual size_t getSymbolCount();
    virtual bool contains(const string searched);
    virtual void replace(const string target, const string replacement);
    virtual void trim();
    virtual void trimLeading();
    virtual void trimTrailing();
    virtual void toUpper();
    virtual void toLower();
    virtual bool isMovableInSort() const;
    virtual bool isNumericLine() const;
    virtual long long getNumericValue() const;
    virtual bool operator< (const Line& other) const;

 protected:
   char lower(int c);
   char upper(int c);
    string content;

};