#include "../headers/Lines/QuotedLine.hpp"


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

void QuotedLine::toUpper() 
{
    size_t firstQuote = content.find('"');
    size_t lastQuote = (firstQuote == std::string::npos) ? std::string::npos : content.find_last_of('"');

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