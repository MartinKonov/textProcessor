#include "../../headers/Lines/LineCreator.hpp"

LineCreator* LineCreator::lineCreator_ = nullptr;

LineCreator* LineCreator::getInstance()
{
    if(lineCreator_ == nullptr)
    {
        lineCreator_ = new LineCreator();
    }
    return lineCreator_;
}

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
bool LineCreator::isQuotedLine(const string &content)
{
    size_t start = content.find_first_not_of(" \t\r\n");
    size_t end = content.find_last_not_of(" \t\r\n");

    return start != std::string::npos
        && end != std::string::npos 
        && content[start] == '"'
        && content[end] == '"';
}
