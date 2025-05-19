#include "../../headers/Lines/Line.hpp"
#include "Line.hpp"


string Line::getLine() {
    return content;
}

size_t Line::getSymbolCount() {
    return content.size();
}

bool Line::contains(const string searched) {
    return content.find(searched) != string::npos;
}

void Line::replace(const string target, const string replacement)
{
    if (!contains(target)) {
        throw std::invalid_argument("Line::replace: substring '" + target 
            + "' not found in \"" + content + "\"");
    }

    size_t pos = content.find(target, pos);
    content.replace(pos, target.length(), replacement);
}
