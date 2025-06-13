/**
 * @file CenterFormatter.cpp
 * @author MK
 * @brief A class that formats input strings by centering them within a specified width.
 */
#include "../../headers/Formatter/CenterFormatter.hpp"

CenterFormatter::CenterFormatter(int formatPoint) : Formatter(formatPoint) {}

/**
 * @brief Returns the type of this formatter.
 * @return A string indicating the type of formatter.
 */
string CenterFormatter::getType() {
    return "CenterFormatter";
}

int CenterFormatter::getFormatPoint() {
    return formatPoint;
}

/**
 * @brief Formats the input string by centering it within a specified width.
 * @param input The input string to format.
 * @param formatPoint The width at which to center the text.
 * @return The formatted string with centered text.
 */
string CenterFormatter::format(string input) {
    string baseString = removeNewLines(input);
    return centerText(baseString, formatPoint);
}


/**
 * @brief Centers the text within a specified width.
 * @param text The text to be centered.
 * @param width The width within which to center the text.
 * @return The centered text as a string, with each line padded with spaces to center it.
 * @details This method splits the text into words and constructs lines that fit within the specified width, centering each line by adding spaces before it.
 */
string CenterFormatter::centerText(const string& text, int width) {
    string result;
    vector<string> words = split(text, ' ');

    string currentLine;
    for (const string& word : words) {
        if (currentLine.length() + word.length() + 1 > width) {
            int padding = (width - currentLine.length()) / 2;
            result += string(padding, ' ') + currentLine + '\n';
            currentLine = word;
        } else {
            if (!currentLine.empty()) {
                currentLine += ' ';
            }
            currentLine += word;
        }
    }

    if (!currentLine.empty()) {
        int padding = (width - currentLine.length()) / 2;
        result += string(padding, ' ') + currentLine + '\n';
    }

    return result;
}