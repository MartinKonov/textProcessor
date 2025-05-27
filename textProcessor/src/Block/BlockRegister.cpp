#include "../../headers/Block/BlockRegister.hpp"

BlockRegister* BlockRegister::instance = nullptr;

BlockRegister::BlockRegister() : DataRegister() {}

BlockRegister::~BlockRegister() {}

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
        throw runtime_error("BlockRegister::addBlock: invalid blockName or document");
    }
    if (startLineIndex > endLineIndex || endLineIndex > document->getNumLines()) {
        throw runtime_error("BlockRegister::addBlock: invalid indices");
    }

    Block* newBlock = new Block(blockName, document->getDocName(), startLineIndex, endLineIndex);

    try{
        addItem(newBlock);
    } catch (const std::runtime_error& e) {
        delete newBlock;
        throw std::runtime_error("BlockRegister::addBlock: " + string(e.what()));
    } catch (const std::logic_error& e) {
        delete newBlock;
    }
}



string BlockRegister::getType() {
    return "BlockRegister";
}

string BlockRegister::getItemName(Block* block) {
    if (block == nullptr) {
        throw std::runtime_error("BlockRegister::getItemName: Block is null");
    }
    return block->getName();
}