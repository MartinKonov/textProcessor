/**
 * @file Block.hpp
 * @author MK
 * @brief A class to represent a block of lines in a document.
 * @version 0.1
 * @date 2025-05-26
 */
#pragma once

#include "../Document/Document.hpp"
#include <string>
using std::string;




class Block {

    public:
        Block() = delete; // Default constructor is deleted to prevent instantiation without parameters.
        Block(string blockName, string documentName, size_t startLineIndex, size_t endLineIndex);
        Block(Block& other);
        Block& operator=(Block& other);
        ~Block();

        bool operator==(Block& other);
        bool operator!=(Block& other);

        string getName() const;
        size_t getStartLineIndex() const;
        size_t getEndLineIndex() const;
        string getDocumentName() const;

    private:
        string blockName;
        string documentName;
        size_t startLineIndex;
        size_t endLineIndex;
};