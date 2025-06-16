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
    if (blockName.empty()) {
        throw runtime_error(ERROR_INVALID_BLOCK_NAME);
    }
    if(!document) {
        throw runtime_error(ERROR_DOCUMENT_NOT_FOUND);
    }
    if (startLineIndex > endLineIndex || endLineIndex > document->getNumLines()) {
        throw runtime_error(ERROR_INDEX_OUT_OF_RANGE);
    }

    Block* newBlock = new Block(blockName, document->getDocName(), startLineIndex, endLineIndex);

    try{
        addItem(newBlock);
    } catch (const runtime_error& e) {
        delete newBlock;
        throw runtime_error(string(e.what()));
    } catch (const std::logic_error& e) {
        delete newBlock;
    }
}

/**
 * @brief Returns the type of the register.
 * 
 * @return string The type of the register.
 */
string BlockRegister::getType() {
    return "BlockRegister";
}

/**
 * @brief Returns the name of the block.
 * 
 * @param block The block for which to get the name.
 * @return string The name of the block.
 * @throws runtime_error if the block is null.
 */
string BlockRegister::getItemName(Block* block) {
    if (block == nullptr) {
        throw runtime_error(ERROR_BLOCK_NOT_FOUND);
    }
    return block->getName();
}

/**
 * @brief Retrieves all blocks associated with a specific document.
 * 
 * @param documentName The name of the document for which to retrieve blocks.
 * @return vector<Block*> A vector containing pointers to the blocks associated with the specified document.
 */
vector<Block*> BlockRegister::getBlocksForDocument(string documentName) {
    vector<Block*> allBlocks = getAll();
    vector<Block*> blocksForDocument;
    
    for(int i = 0; i < allBlocks.size(); i++) {
        if(allBlocks[i]->getDocumentName() == documentName){
            blocksForDocument.push_back(allBlocks[i]);
        }
    }

    return blocksForDocument;
}

/**
 * @brief Shows all blocks associated with a specific document in a formatted string.
 * 
 * @param documentName The name of the document for which to show blocks.
 * @return string A formatted string containing the details of all blocks associated with the specified document.
 */
string BlockRegister::showAllForDocument(string documentName) {
    
    vector<Block*> allBlocks = getAll();
    string out;
    out += "Blocks for document: " + documentName + "\n";
    out += "-----------------------------------\n";
    out += "Name | start Line Index | end Line index\n";
    for (Block* block : items) {
        if(block->getDocumentName() == documentName) {
            out += parser->serialize(block);
        }
    }
    return out;
}