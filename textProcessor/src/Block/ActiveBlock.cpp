#include "../../headers/Block/ActiveBlock.hpp"




ActiveBlock::ActiveBlock(BlockRegister* blockRegister, Block* activeBlock = nullptr) {
    this->blockRegister = blockRegister;
    this->activeBlock = activeBlock;
}

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

void ActiveBlock::removeActiveBlock() {
    activeBlock = nullptr;
}

Block* ActiveBlock::getActiveBlock() {
    if (activeBlock != nullptr) {
        return activeBlock; 
    }
    throw runtime_error("ActiveBlock:: getActiveBlock: Active block hasn't been set yet.");
}
