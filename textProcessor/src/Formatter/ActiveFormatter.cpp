#include "../../headers/Formatter/ActiveFormatter.hpp"



ActiveFormatter::ActiveFormatter() {
    this->formatter = new DirectFormatter();
}

ActiveFormatter::~ActiveFormatter() {
    delete formatter;
}

void ActiveFormatter::setFormatter(string formatterType) {
    if (formatter->getType() == formatterType) {
        return;
    }
    
    if (formatter) {
        delete formatter;
    }

    if (formatterType == "CenterFormatter") {
        formatter = new CenterFormatter();
    } else if (formatterType == "WrapFormatter") {
        formatter = new WrapFormatter();
    } else if (formatterType == "DirectFormatter") {
        formatter = new DirectFormatter();
    } else {
        throw std::runtime_error("ActiveFormatter::setFormatter: Unknown formatter type");
    }
}

string ActiveFormatter::getFormattedString(string input, int formatPoint) {
    return formatter->format(input, formatPoint);
}