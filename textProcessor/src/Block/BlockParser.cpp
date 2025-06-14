#include "../../headers/Block/BlockParser.hpp"

BlockParser* BlockParser::instance = nullptr;
/**
 * @brief Returns the singleton instance of BlockParser.
 * 
 * @return BlockParser* The singleton instance of BlockParser.
 */
BlockParser* BlockParser::getInstance()
{
    if (instance == nullptr) {
        instance = new BlockParser();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of BlockParser.
 * 
 * This method deletes the instance of BlockParser and sets it to nullptr.
 */
void BlockParser::destroyInstance()
{
    delete instance;
    instance = nullptr;
}

/**
 * @brief Parses a block from a string content.
 * @param content The string containing block information.
 * @return Block* A pointer to the created Block object.
 */
Block* BlockParser::parse(const std::string content) 
{
    vector<string> parts = split(content, '|');
    if (parts.size() != 4) {
        throw std::runtime_error("BlockParser::parseBlock: Invalid block format");
    }

    string blockName = parts[0];
    string docName = parts[1];
    size_t startLineIndex = std::stoul(parts[2]);
    size_t endLineIndex = std::stoul(parts[3]);

    return new Block(blockName, docName, startLineIndex, endLineIndex);
}

/**
 * @brief Serializes a Block object into a string format.
 * 
 * @param block The Block object to serialize.
 * @return string The serialized representation of the block.
 */
string BlockParser::serialize(Block* block) 
{
    return block->getName() + "|"
           + to_string(block->getStartLineIndex()) + "|"
           + to_string(block->getEndLineIndex()) + "\n";
}