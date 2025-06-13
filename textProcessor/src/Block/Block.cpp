#include "../../headers/Block/Block.hpp"


Block::Block(string blockName, string documentName, size_t startLineIndex, size_t endLineIndex)
{
    this->blockName = blockName;
    this->documentName = documentName;
    this->startLineIndex = startLineIndex;
    this->endLineIndex = endLineIndex;
}

Block::~Block()
{
    // No dynamic memory to free, as Block is managed by Blockregsiter
}

/**
 * @brief Copy constructor for Block.
 * @param other The Block object to copy from.
 */
Block::Block(Block& other) {
    this->blockName = other.blockName;
    this->documentName = other.documentName;
    this->startLineIndex = other.startLineIndex;
    this->endLineIndex = other.endLineIndex;
}

/**
 * @brief Assignment operator for Block.
 * @param other The Block object to assign from.
 * @return Block& Reference to the current object.
 */
Block& Block::operator=(Block& other) {
    if(this != &other){
        this->blockName = other.blockName;
        this->documentName = other.documentName;
        this->startLineIndex = other.startLineIndex;
        this->endLineIndex = other.endLineIndex;
    }

    return *this;
}

/**
 * @brief Equality operator for Block.
 * @param other The Block object to compare with.
 * @return bool True if the blocks are equal, false otherwise.
 */
bool Block::operator==(Block& other) {
    return (this->blockName == other.blockName)
            && (this->documentName == other.documentName)
            && (this->startLineIndex == other.startLineIndex)
            && (this->endLineIndex == other.endLineIndex);
}

/**
 * @brief Inequality operator for Block.
 * @param other The Block object to compare with.
 * @return bool True if the blocks are not equal, false otherwise.
 */
bool Block::operator!=(Block& other) {
    return (this->blockName != other.blockName)
            || (this->documentName != other.documentName)
            || (this->startLineIndex != other.startLineIndex)
            || (this->endLineIndex != other.endLineIndex);
}

/**
 * @brief Returns the name of the block.
 * @return string The name of the block.
 */
string Block::getName() const
{
    return blockName;
}

/**
 * @brief Returns the index of the first line in the block.
 * @return size_t The index of the first line in the block.
 */
size_t Block::getStartLineIndex() const
{
    return startLineIndex;
}

/**
 * @brief Returns the index of the last line in the block.
 * @return size_t The index of the last line in the block.
 */
size_t Block::getEndLineIndex() const
{
    return endLineIndex;
}


/**
 * @brief Returns the name of the document associated with this block.
 * @return string The name of the document.
 */
string Block::getDocumentName() const
{
    return documentName;
}
