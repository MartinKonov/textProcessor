/**
 * @file BlockParser.hpp
 * @author MK
 * @brief A class to parse blocks of lines in a document.
 * @version 0.1
 * @date 2025-05-26
 */
#pragma once
#include "Block.hpp"
#include "../../dataFiles/DataFiles.hpp"
#include "../GenericDataClasses/DataParser.hpp"
#include <vector>

using std::vector;
using std::stoul;
using std::to_string;

/**
 * @brief A class to parse blocks of lines in a document.
 */
class BlockParser : public DataParser<BlockParser, Block> {
 public:
    static BlockParser* getInstance();
    static void destroyInstance();

    string serialize(Block* block);
    Block* parse(const std::string content);

   static constexpr const char* DATA_FILE = BLOCK_DATA_FILE;

 private:
    BlockParser() = default;
    BlockParser(const BlockParser&) = delete;
    BlockParser& operator=(const BlockParser&) = delete;
    ~BlockParser() = default;

    static BlockParser* instance;
};