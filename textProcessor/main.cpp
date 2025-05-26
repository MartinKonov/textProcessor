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

using namespace std;

int main() {
    try {
        // Step 1: Get instances
        DocumentRegister* docReg = DocumentRegister::getInstance();
        BlockParser* blockParser = BlockParser::getInstance();
        BlockRegister* blockReg = BlockRegister::getInstance();

        // Step 2: Add a document
        string testDoc = string(DOCUMENT_TEST_FILES) + "/example.txt";
        docReg->addDocument(testDoc);
        cout << "Document loaded successfully.\n";

        // Step 3: Retrieve document
        Document* doc = docReg->getDocument(testDoc);
        cout << "Document Content:\n" << doc->toString() << endl;

        cout << "Doc Num Lines: " << doc->getNumLines() << endl;
 
        // Step 6: Load blocks from file
        // vector<Block*> loadedBlocks = blockParser->loadBlocks();
        // cout << "Loaded " << loadedBlocks.size() << " blocks:\n";
        // for (auto b : loadedBlocks) {
        //     cout << "- " << b->getBlockName() << " from doc '" 
        //          << b->getDocumentName() << "'\n";
        //     delete b; // clean up loaded block
        // }

        // Step 7: Register the block
        blockReg->addBlock("TestBlock", doc, 1, 10);
        cout << "Block registered.\n";

        // Step 8: Retrieve and print block from registry
        Block* retrieved = blockReg->getBlock("TestBlock");
        if (retrieved != nullptr) {
            cout << "Retrieved block: " << retrieved->getBlockName()
                 << " from document " << retrieved->getDocumentName() << endl;
        }

        // Cleanup
        //blockReg->removeBlock("TestBlock");
        //docReg->removeDocument(testDoc);
        //delete block;

        blockReg->destroyInstance();
        blockParser->destroyInstance();
        docReg->destroyInstance();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
