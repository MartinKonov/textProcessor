/**
 * @file ActiveFormat.hpp
 * @brief Declaration of the ActiveFormat class, which manages the active formatter for string formatting.
 * @details This class is a singleton that allows setting and getting formatted strings using different formatter types.
 */

#pragma once
#include "CenterFormatter.hpp"
#include "DirectFormatter.hpp"
#include "WrapFormatter.hpp"


class ActiveFormatter {

 public:
    static ActiveFormatter* getInstance();
    static void destroyInstance();
    void setFormatter(string formatterType);
    string getFormattedString(string input, int formatPoint);

 private:
    static ActiveFormatter* instance;
    Formatter* formatter;

    ActiveFormatter();
};