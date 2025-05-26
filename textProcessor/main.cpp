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
#include "headers/Document/DocumentParser.hpp"
#include "headers/Document/Document.hpp"

int main() {


    // Create a FileManager instance
    FileManager* fileManager = FileManager::getInstance();
    // Create a DocumentParser instance
    DocumentParser* documentParser = DocumentParser::getInstance();
    // Load a document
    Document* document = nullptr;
    try {
        document = documentParser->load("/home/mkonov/cProjects/UNI/projectOOP/textProcessor/textProcessor/textDocumentFiles/example_copy.txt");
        std::cout << "Document loaded successfully: " << document->getDocName() << std::endl;
        std::cout << "Document contents:\n" << document->toString() << std::endl;
        std::cout << "Updated document contents:\n" << *document << std::endl;


    } catch (const std::runtime_error& e) {
        std::cerr << "Error loading document: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}