/**
 * @file LineCreator.cpp
 * @author MK
 * @brief A singleton class to create Line objects based on the content of the line.
 * @version 0.1
 * @date 2025-05-18
 */

#include "../../headers/Lines/LineCreator.hpp"


LineCreator* LineCreator::lineCreator_ = nullptr;

/**
 * @brief Returns the singleton instance of LineCreator
 *
 * @return LineCreator* The singleton instance of LineCreator
 */
LineCreator* LineCreator::getInstance()
{
    if(lineCreator_ == nullptr)
    {
        lineCreator_ = new LineCreator();
    }
    return lineCreator_;
}

void LineCreator::destroyInstance()
{
    delete lineCreator_;
    lineCreator_ = nullptr;
}

/**
 * @brief Creates a Line object based on the content of the line
 *
 * @param content The content of the line
 * @return Line* A pointer to the created Line object
 */
Line* LineCreator::createLine(string content)
{
    if(isNumberedLine(content))
    {
        return new NumberedLine(content);
    }
    else if (isNumericLine(content))
    {
        return new NumericLine(content);
    }
    else if(isQuotedLine(content))
    {
        return new QuotedLine(content);
    }
    else
    {
        return new DefaultLine(content);
    }
}

/**
 * @brief Checks if the line is a numbered line
 *
 * @param content The content of the line
 * @return true if the line is a numbered line
 * @return false otherwise
 */
bool LineCreator::isNumberedLine(const string& content)
{
    size_t p = content.find_first_not_of(" \t\r\n");
    if (p != std::string::npos && isdigit((unsigned char)(content[p]))) {
        size_t q = p;
        while (q < content.size() && isdigit((unsigned char)(content[q]))) {
            ++q;
        }
        if (q < content.size() && content[q] == '.') {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if the line is a numeric line
 *
 * @param content The content of the line
 * @return true if the line is a numeric line
 * @return false otherwise
 */
bool LineCreator::isNumericLine(const string &content)
{
    size_t start = content.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return false;

    size_t end = content.find_last_not_of(" \t\r\n");
    std::string mid = content.substr(start, end - start + 1);

    if (mid.empty()) return false;

    for (char c : mid) {
        if (!isdigit((unsigned char)(c))) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if the line is a quoted line
 *
 * @param content The content of the line
 * @return true if the line is a quoted line
 * @return false otherwise
 */
bool LineCreator::isQuotedLine(const string &content)
{
    size_t start = content.find_first_not_of(" \t\r\n");
    size_t end = content.find_last_not_of(" \t\r\n");

    return start != std::string::npos
        && end != std::string::npos 
        && content[start] == '"'
        && content[end] == '"';
}
