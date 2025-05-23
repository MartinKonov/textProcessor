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
#include "headers/FileManager.hpp"

int main() {

    FileManager manager;

    manager.open("/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example.txt");
    std::string content = manager.getContents("/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example.txt");

    std::cout << "Loaded Content:\n" << content << std::endl;

    manager.setContent("/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example.txt", content + "\nNew line added.");
    manager.save("/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example.txt");

    manager.saveAs("/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example.txt", "/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example_copy.txt");

    manager.close("/home/mkonov/tp/textProcessor/textProcessor/textDocumentFiles/example.txt");

    return 0;
}