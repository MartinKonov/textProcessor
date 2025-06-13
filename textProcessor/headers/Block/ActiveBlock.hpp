/**
 * @file ActiveBlock.hpp
 * @author MK
 * @brief A class to manage the active block in the text processor application.
 */
#pragma once
#include "BlockRegister.hpp"


/**
 * @brief A class to manage the active block in the text processor application.
 */
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