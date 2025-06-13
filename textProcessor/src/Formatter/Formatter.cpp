/**
 * @file Formatter.cpp
 * @author MK
 * @brief A class that provides methods for formatting strings, including removing new lines and splitting strings.
 */
#include "../../headers/Formatter/Formatter.hpp"



/**
 * @brief Removes new line characters from the input string and replaces them with spaces.
 * @param input The input string from which new lines will be removed.
 */
string Formatter::removeNewLines(const string& input) {
    string result;
    for (char ch : input) {
        if (ch != '\n') {
            result += ch;
        } else {
            result += ' ';
        }
    }
    return result;
}

/**
 * @brief Splits a string into a vector of strings based on a delimiter.
 * @param str The string to be split.
 * @param delimiter The character used to split the string.
 * @return A vector of strings resulting from the split operation.
 * @details This method is used to parse lines from the data file.
 */
vector<string> Formatter::split(const string& str, char delimiter) {
    vector<string> result;
    string current;
    for (char ch : str) {
        if (ch == delimiter) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += ch;
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}