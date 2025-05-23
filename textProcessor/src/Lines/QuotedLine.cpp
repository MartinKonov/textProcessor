/**
 * @file QuotedLine.hpp
 * @author MK
 * @brief A class to represent a line that is enclosed in double quotes.
 * @version 0.1
 * @date 2025-05-18
 */
#include "../../headers/Lines/QuotedLine.hpp"


/**
 * @brief If a line is enclosed in double quotes (possibly with leading/trailing spaces
 *        outside the quotes), then do NOT apply trim inside the quotes
 * 
 */
void QuotedLine::trim() 
{
    size_t firstNonWS = content.find_first_not_of(" \t\r\n");
    if (firstNonWS == std::string::npos) {
        content.clear();
        return;
    }

    if (content[firstNonWS] == '"') {
        size_t closingQuote = content.find_last_of('"');
        if (closingQuote == firstNonWS) {
            Line::trim();
            return;
        }
        std::string inner = content.substr(firstNonWS, closingQuote - firstNonWS + 1);
        content = inner; 
        return;
    }  
}

/**
 * @brief If a line is enclosed in double quotes (possibly with leading/trailing spaces
 *        outside the quotes), then do NOT apply trim inside the quotes
 * 
 */
void QuotedLine::trimLeading()
{
    size_t firstNonWS = content.find_first_not_of(" \t\r\n");
    if (firstNonWS == std::string::npos) {
        content.clear();
        return;
    }

    if (content[firstNonWS] == '"') {
        size_t closingQuote = content.find_last_of('"');
        if (closingQuote == firstNonWS) {
            Line::trimLeading(); 
        } else {
            content = content.substr(firstNonWS);
        }
    } else {
        Line::trimLeading();
    }
}

/**
 * @brief If a line is enclosed in double quotes (possibly with leading/trailing spaces
 *        outside the quotes), then do NOT apply trim inside the quotes
 * 
 */
void QuotedLine::trimTrailing()
{
    size_t firstNonWS = content.find_first_not_of(" \t\r\n");
    if (firstNonWS == std::string::npos) 
    {
        content.clear();
        return;
    }

    if (content[firstNonWS] == '"') 
    {
        size_t closingQuote = content.find_last_of('"');
        if (closingQuote == firstNonWS) {
            Line::trimTrailing();
        } else {
            content = content.substr(0, closingQuote + 1);
        }
    } else 
    {
        Line::trimTrailing();
    }
}

/**
 * @brief use toUpper only outside of the quotes
 * 
 */
void QuotedLine::toUpper() 
{
    size_t firstQuote = findFirstQuote();
    size_t lastQuote = findLastQuote(firstQuote);

    if (firstQuote == std::string::npos || lastQuote == firstQuote) {
        for (size_t i = 0; i < content.size(); ++i) {
            content[i] = std::toupper((unsigned char)content[i]);
        }
        return;
    }

    for (size_t i = 0; i < content.size(); ++i) {
        if (i < firstQuote || i > lastQuote) {
            content[i] = std::toupper((unsigned char)content[i]); 
        }
    }
}

/**
 * @brief use toLower only outside of the quotes
 * 
 */
void QuotedLine::toLower()
{
    size_t firstQuote = findFirstQuote();
    size_t lastQuote = findLastQuote(firstQuote);

    if (firstQuote == std::string::npos || lastQuote == firstQuote) {
        for (size_t i = 0; i < content.size(); ++i) {
            content[i] = std::tolower((unsigned char)content[i]);
        }
        return;
    }

    for (size_t i = 0; i < content.size(); ++i) {
        if (i < firstQuote || i > lastQuote) {
            content[i] = std::tolower((unsigned char)content[i]); 
        }
    }
}

/**
 * @brief Finds the first quote in the line
 * 
 * @return size_t The position of the first quote
 */
size_t QuotedLine::findFirstQuote() 
{
    return content.find('"');
}

/**
 * @brief Finds the last quote in the line
 * 
 * @param firstQuote The position of the first quote
 * @return size_t The position of the last quote
 */
size_t QuotedLine::findLastQuote(size_t firstQuote)
{
    if(firstQuote == string::npos)
    {
        return string::npos;
    }

    return content.find_last_not_of('"');
}
