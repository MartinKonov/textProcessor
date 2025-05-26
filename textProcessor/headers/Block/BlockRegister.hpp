/**
 * @file BlockRegister.hpp
 * @author MK
 * @brief A singleton class to manage a collection of blocks within documents.
 * @version 0.1
 * @date 2025-05-26
 */

#pragma once
#include "Block.hpp"
#include "BlockParser.hpp"



class BlockRegister {
 public:
    static BlockRegister* getInstance();
    static void destroyInstance();

    void addBlock(string blockName, Document* document, size_t startLineIndex, size_t endLineIndex);
    void removeBlock(string blockName);
    Block* getBlock(string blockName);
    
    friend ostream& operator<< (ostream& os, BlockRegister& blockRegister);
 private:
    BlockRegister();
    BlockRegister(const BlockRegister&) = delete;
    BlockRegister& operator=(const BlockRegister&) = delete;
    ~BlockRegister();

    static BlockRegister* instance;

    BlockParser* blockParser;
    vector<Block*> blocks;

    bool isValidStartAndEndIndex(size_t startLineIndex, size_t endLineIndex, Document* document) const;
    int findIndex(string blockName);
};