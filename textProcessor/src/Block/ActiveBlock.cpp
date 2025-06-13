#include "../../headers/Block/ActiveBlock.hpp"

/**
 * @file ActiveBlock.cpp
 * @author MK
 */
ActiveBlock::ActiveBlock(BlockRegister* blockRegister, Block* activeBlock) {
    this->blockRegister = blockRegister;
    this->activeBlock = activeBlock;
}

/**
 * @brief Sets the active block for the current active document.
 * @param blockName The name of the block to set as active.
 * @param activeDocument The currently active document.
 * @throws std::runtime_error if the block with the given name does not exist for the current active document.
 */
void ActiveBlock::setActiveBlock(string blockName, Document* activeDocument) {
    vector<Block*> blocksForDoc = blockRegister->getBlocksForDocument(activeDocument->getDocName());

    for(Block* block : blocksForDoc) {
        if(blockName == block->getName()) {
            activeBlock = block;
            return;
        }
    }

    throw runtime_error("ActiveBlock:: setActiveBlock: A block with that name doesn't exist for current active document");
}

/**
 * @brief Removes the currently active block.
 * This method sets the active block to nullptr, effectively removing it.
 */
void ActiveBlock::removeActiveBlock() {
    activeBlock = nullptr;
}

/**
 * @brief Returns the currently active block.
 * @return A pointer to the currently active block, or nullptr if no block is active.
 */
Block* ActiveBlock::getActiveBlock() {
    return activeBlock;
}
