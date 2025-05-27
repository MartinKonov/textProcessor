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
#include "headers/Document/DocumentRegister.hpp"
#include "headers/Block/BlockRegister.hpp"
#include "headers/Block/BlockParser.hpp"
#include "headers/Macro/MacroRegister.hpp"

using namespace std;

void testMacroRegister() {
    cout << "\n=== MacroRegister Tests ===\n";
    MacroRegister* macroReg = MacroRegister::getInstance();

    try {
        macroReg->addMacro("macro1", {"cmd1", "cmd2", "cmd3"});
        macroReg->addMacro("macro2", {"cmdX", "cmdY"});
    } catch (const std::exception& e) {
        cerr << "Error adding macro: " << e.what() << endl;
    }

    try {
        string result = macroReg->showAll();
        cout << "All Macros:\n" << result;
    } catch (const std::exception& e) {
        cerr << "Error showing macros: " << e.what() << endl;
    }

    try {
        Macro* macro = macroReg->getItem("macro1");
        cout << "Retrieved macro1 with commands: ";
        for (const auto& cmd : macro->getCommandNames()) {
            cout << cmd << " ";
        }
        cout << endl;
    } catch (const std::exception& e) {
        cerr << "Error retrieving macro: " << e.what() << endl;
    }

    // Test duplicate
    try {
        macroReg->addMacro("macro1", {"cmdZ"});
    } catch (const std::exception& e) {
        cout << "Expected duplicate error: " << e.what() << endl;
    }

    MacroRegister::destroyInstance();
}

void testBlockRegister() {
    cout << "\n=== BlockRegister Tests ===\n";
    BlockRegister* blockReg = BlockRegister::getInstance();

    // Create a fake Document
    vector<Line*> lines;
    Document doc("myDoc", lines);
    doc.addLine("Line 1");
    doc.addLine("Line 2");
    doc.addLine("Line 3");

    try {
        blockReg->addBlock("blockA", &doc, 0, 2);
        blockReg->addBlock("blockB", &doc, 1, 2);
    } catch (const std::exception& e) {
        cerr << "Error adding block: " << e.what() << endl;
    }

    try {
        string result = blockReg->showAll();
        cout << "All Blocks:\n" << result;
    } catch (const std::exception& e) {
        cerr << "Error showing blocks: " << e.what() << endl;
    }

    try {
        Block* block = blockReg->getItem("blockA");
        cout << "Retrieved blockA: " << block->getName()
             << ", document: " << block->getDocumentName()
             << ", lines: " << block->getStartLineIndex() << "-" << block->getEndLineIndex() << endl;
    } catch (const std::exception& e) {
        cerr << "Error retrieving block: " << e.what() << endl;
    }

    // Test invalid block
    try {
        blockReg->addBlock("", &doc, 0, 1);
    } catch (const std::exception& e) {
        cout << "Expected invalid name error: " << e.what() << endl;
    }

    BlockRegister::destroyInstance();
}

int main() {
    testMacroRegister();
    testBlockRegister();

    return 0;
}