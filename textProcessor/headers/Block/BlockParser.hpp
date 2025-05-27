/**
 * @file BlockParser.hpp
 * @author MK
 * @brief A class to parse blocks of lines in a document.
 * @version 0.1
 * @date 2025-05-26
 */
#pragma once
#include "../FileManager.hpp"
#include "Block.hpp"
#include "../Document/Document.hpp"
#include "../Document/DocumentRegister.hpp"
#include "../DataFiles.hpp"
#include <vector>

using std::vector;
using std::stoul;

class BlockParser {
 public:
    static BlockParser* getInstance();
    static void destroyInstance();

    void save(Block* block);
    void save(const vector<Block*> blocks);
    string serializeBlock(Block* block);
    vector<Block*> loadBlocks();

 private:
    BlockParser();
    BlockParser(const BlockParser&) = delete;
    BlockParser& operator=(const BlockParser&) = delete;
    ~BlockParser();

    static BlockParser* instance;

    DocumentRegister* documentRegister;
    FileManager* fileManager;
    Block* parseBlock(const std::string content);
    vector<string> split(const std::string& str, char delimiter);
};