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
#include "Lines/Line.hpp"

int main() {

    Line line("Hello, World!");
    std::cout << "Line content: " << line.getLine() << std::endl;

    return 0;
}