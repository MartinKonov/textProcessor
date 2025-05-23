/**
 * @file main.cpp
 * @author MK
 * @brief 
 * @version 0.1
 * @date 2025-05-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <iostream>
#include <vector>
#include "headers/Lines/NumberedLine.hpp"
#include "headers/Lines/NumericLine.hpp"
#include "headers/Lines/QuotedLine.hpp"
#include "headers/Lines/LineCreator.hpp"

int main() {

    LineCreator* creator = LineCreator::getInstance();
    
    std::vector<std::string> testInputs = {
        "1. This is a numbered line",
        "  42  ",
        "  \"  This is a quoted line   \"   ",
        "Just some random line",
        "003. Another numbered line",
        "\"\"",
        "Not really \"quoted\" properly",
        "123abc"
    };

    for (const std::string& input : testInputs) {
        std::cout << "\nInput: \"" << input << "\"" << std::endl;

        Line* line = creator->createLine(input);

        std::cout << "\nLine: " << line->getLine() << std::endl;
        line->toUpper();
        std::cout << "\ntoUpper: " << line->getLine() << std::endl; 
        line->toLower();
        std::cout << "\ntoLower: " << line->getLine() << std::endl;
        line->trim();
        std::cout << "\ntrim: " << line->getLine() << std::endl;
        std::cout << "\nsymbolCOunt: " << line->getSymbolCount() << std::endl;
    }

    return 0;
}