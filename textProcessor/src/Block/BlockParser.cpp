#include "../../headers/Block/BlockParser.hpp"
#include <iostream>

BlockParser* BlockParser::instance = nullptr;

BlockParser::BlockParser()
{
    this->documentRegister = DocumentRegister::getInstance();
    this->fileManager = FileManager::getInstance();
}

BlockParser::~BlockParser()
{
    // No dynamic memory to free, as DocumentParser and FileManager are singletons
}

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
 * @brief Saves a block to the document.
 * 
 * @param document The document to which the block belongs.
 * @param block The block to save.
 * @throws runtime_error if the file cannot be saved.
 */
void BlockParser::save(Block* block) 
{
    string content = serializeBlock(block);

    try{
        fileManager->loadFile(BLOCK_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("BlockParser::save: " + string(e.what()));
    }

    string existingContent = fileManager->getContents(BLOCK_DATA_FILE);
    string newContent = existingContent + content;
    fileManager->setContent(BLOCK_DATA_FILE, newContent);

    try {
        fileManager->save(BLOCK_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("BlockParser::save: " + string(e.what()));
    }
}

/**
 * @brief Loads all blocks from the block data file.
 * 
 * @return vector<Block*> A vector of pointers to Block objects.
 */
vector<Block*> BlockParser::loadBlocks() 
{
    vector<Block*> blocks;
    try {
        fileManager->loadFile(BLOCK_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("BlockParser::loadBlocks: " + string(e.what()));
    }

    string content = fileManager->getContents(BLOCK_DATA_FILE);
    vector<string> lines = split(content, '\n');

    for (const string& line : lines) {
        try {
            Block* block = parseBlock(line);
            blocks.push_back(block);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("BlockParser::loadBlocks: " + string(e.what()));
        }
    }
    return blocks;
}

/**
 * @brief Splits a string into a vector of strings based on a delimiter.
 * 
 * @param str The string to split.
 * @param delimiter The character used to split the string.
 * @return vector<string> A vector of strings obtained by splitting the input string.
 */
vector<string> BlockParser::split(const std::string& str, char delimiter) 
{
    vector<string> result;
    string current;

    for(char ch : str) {
        if (ch == delimiter) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += ch;
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}

/**
 * @brief Parses a block from a string content.
 * @param content The string containing block information.
 * @return Block* A pointer to the created Block object.
 */
Block* BlockParser::parseBlock(const std::string content) 
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

string BlockParser::serializeBlock(Block* block) 
{
    return block->getBlockName() + "|" + block->getDocumentName() + "|" +
           to_string(block->getStartLineIndex()) + "|" +
           to_string(block->getEndLineIndex()) + "\n";
}