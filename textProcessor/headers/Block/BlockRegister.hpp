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
#include "../GenericDataClasses/DataRegister.hpp"



class BlockRegister : public DataRegister<BlockRegister, Block, BlockParser> {
 public:
    static BlockRegister* getInstance();
    static void destroyInstance();

    void addBlock(string blockName, Document* document, size_t startLineIndex, size_t endLineIndex);

    string getType();

    string getItemName(Block* block);

    vector<Block*> getBlocksForDocument(string documentName);

    string showAllForDocument(string documentName);

 private:
    BlockRegister();
    ~BlockRegister();
    BlockRegister(const BlockRegister&) = delete;
    BlockRegister& operator=(const BlockRegister&) = delete;

    static BlockRegister* instance;
    
};