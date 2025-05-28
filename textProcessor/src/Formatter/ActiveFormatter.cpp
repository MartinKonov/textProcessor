#include "../../headers/Formatter/ActiveFormatter.hpp"



ActiveFormatter* ActiveFormatter::instance = nullptr;
ActiveFormatter* ActiveFormatter::getInstance() {
    if (instance == nullptr) {
        instance = new ActiveFormatter();
    }
    return instance;
}

void ActiveFormatter::destroyInstance() {
    delete instance;
    instance = nullptr;
}

ActiveFormatter::ActiveFormatter() {
    this->formatter = new DirectFormatter();
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
    if (!formatter) {
        throw std::runtime_error("ActiveFormatter::getFormattedString: No formatter set");
    }
    return formatter->format(input, formatPoint);
}