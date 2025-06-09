#pragma once
#include "BlockRegister.hpp"



class ActiveBlock {

public:
    ActiveBlock() = delete;
    ActiveBlock(BlockRegister* blockRegister, Block* activeBlock = nullptr);
    ~ActiveBlock() = default;

    void setActiveBlock(string blockName, Document* activeDocument);
    Block* getActiveBlock();
    void removeActiveBlock();

private:
    Block* activeBlock;
    BlockRegister* blockRegister;
};