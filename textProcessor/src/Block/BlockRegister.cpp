#include "../../headers/Block/BlockRegister.hpp"
#include <iostream>

BlockRegister* BlockRegister::instance = nullptr;

BlockRegister::BlockRegister() {
    this->blockParser = BlockParser::getInstance();
    try{
        this->blocks = blockParser->loadBlocks();
        for(auto& block: blocks){
            cout<< "BlockRegister::BlockRegister: Loaded block: " 
                << block->getBlockName() << " from document: " 
                << block->getDocumentName() << endl;
        }
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("BlockRegister::BlockRegister: " + string(e.what()));
    }
}

BlockRegister::~BlockRegister() {
    for (auto& block : blocks) {
        delete block;
    }
    blocks.clear();
}

/**
 * @brief Returns the singleton instance of BlockRegister.
 * 
 * @return BlockRegister* The singleton instance of BlockRegister.
 */
BlockRegister* BlockRegister::getInstance() {
    if (instance == nullptr) {
        instance = new BlockRegister();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of BlockRegister.
 * 
 * This method deletes the instance of BlockRegister and sets it to nullptr.
 */
void BlockRegister::destroyInstance() {
    delete instance;
    instance = nullptr;
}
/**
 * @brief Adds a block to the register.
 * 
 * @param blockName The name of the block.
 * @param document The document to which the block belongs (the active document).
 * @param startLineIndex The starting line index of the block.
 * @param endLineIndex The ending line index of the block.
 */
void BlockRegister::addBlock(string blockName, Document* document, size_t startLineIndex, size_t endLineIndex) {
    if (blockName.empty() || document == nullptr) {
        throw std::runtime_error("BlockRegister::addBlock: Invalid block name or document");
    }

    if(isValidStartAndEndIndex(startLineIndex, endLineIndex, document) == false) {
        throw std::runtime_error("BlockRegister::addBlock: Invalid start or end line index");
    }

    if(findIndex(blockName) != -1) {
        return;
    }

    Block* newBlock = new Block(blockName, document->getDocName(), startLineIndex, endLineIndex);
    blocks.push_back(newBlock);
    
    try {
        blockParser->save(newBlock);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("BlockRegister::addBlock: " + string(e.what()));
    }
}

bool BlockRegister::isValidStartAndEndIndex(size_t startLineIndex, size_t endLineIndex, Document* document) const {
    if (startLineIndex > endLineIndex || startLineIndex < 0 || endLineIndex < 0) {
        return false;
    }

    if(endLineIndex > document->getNumLines())
    {
        return false;
    }

    return true;
}

int BlockRegister::findIndex(string blockName)
{
    for (size_t i = 0; i < blocks.size(); ++i) {
        if (blocks[i]->getBlockName() == blockName) {
            return i;
        }
    }
    return -1;
} 

/**
   * @brief Removes a block from the register.
   *
   * @param blockName The name of the block to remove.
   */
void BlockRegister::removeBlock(string blockName) {
    if(blockName.empty()) {
        throw std::runtime_error("BlockRegister::removeBlock: Invalid block name");
    }

    int index = findIndex(blockName);
    if (index == -1) {
        return;
    }

    Block* blockToRemove = blocks[index];
    blocks.erase(blocks.begin() + index);
    delete blockToRemove;
    try {
        blockParser->save(blockToRemove);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("BlockRegister::removeBlock: " + string(e.what()));
    }
}

/**
 * @brief Retrieves a block by its name.
 * 
 * @param blockName The name of the block to retrieve.
 * @return Block* Pointer to the block if found, nullptr otherwise.
 */
Block* BlockRegister::getBlock(string blockName){
    if(blockName.empty()) {
        throw std::runtime_error("BlockRegister::getBlock: Invalid block name");
    }

    int index = findIndex(blockName);
    if (index == -1) {
        throw std::runtime_error("BlockRegister::getBlock: Block not found");
    }

    return blocks[index];
}

/**
 * @brief Overloads the << operator to print the block register.
 * 
 * @param os The output stream.
 * @param blockRegister The block register to print.
 * @return ostream& The output stream after printing the block register.
 */
ostream& operator<<(ostream& os, BlockRegister& blockRegister) {
    os << "Block Name | Document Name | Start Line Index | End Line Index\n";
    for (const auto& block : blockRegister.blocks) {
        os << blockRegister.blockParser->serializeBlock(block);
    }
    return os;
}