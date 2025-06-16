/**
 * @file DataParser.hpp
 * @brief A template class for parsing data items.
 * This class provides methods to save and load data items from a file.
 * It is designed to be extended by derived classes that implement specific serialization and parsing logic.
 */

#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include "FileManager.hpp"

using std::string;
using std::vector;

/**
 * @class DataParser
 * @brief A template class for parsing data items.
 */
template <typename Derived, typename T>
class DataParser {
public:
    /**
     * @brief Saves a single item to the data file.
     * @param item Pointer to the item to be saved.
     * @throws std::runtime_error if there is an error during file operations.
     * @details This method appends the serialized item to the data file.
    */
    void save(T* item) {
        string content = ((Derived*)this)->serialize(item);

        try {
            fileManager->loadFile(Derived::DATA_FILE);
        } catch (const runtime_error& e) {
            throw runtime_error(string(e.what()));
        }

        string existingContent = fileManager->getContents(Derived::DATA_FILE);
        string newContent = existingContent + '\n' + content;

        fileManager->setContent(Derived::DATA_FILE, newContent);

        try {
            fileManager->save(Derived::DATA_FILE);
        } catch (const runtime_error& e) {
            throw runtime_error(string(e.what()));
        }
    }

    /**
     * @brief Saves multiple items to the data file.
     * @param items Vector of pointers to items to be saved.
     * @throws std::runtime_error if there is an error during file operations.
     * @details This method concatenates the serialized items and saves them to the data file.
    */
    void save(const vector<T*>& items) {
        string content;
        for (T* item : items) {
            content += ((Derived*)this)->serialize(item);
        }

        try {
            fileManager->loadFile(Derived::DATA_FILE);
            fileManager->setContent(Derived::DATA_FILE, content);
            fileManager->save(Derived::DATA_FILE);
        } catch (const runtime_error& e) {
            throw runtime_error(string(e.what()));
        }
    }

    /**
     * @brief Loads items from the data file.
     * @return A vector of pointers to the loaded items.
     * @throws std::runtime_error if there is an error during file operations or parsing.
     * @details This method reads the content of the data file, splits it into lines, and parses each line into an item.
    */
    vector<T*> load() {
        vector<T*> items;
        try {
            fileManager->loadFile(Derived::DATA_FILE);
        } catch (const runtime_error& e) {
            throw runtime_error(string(e.what()));
        }

        string content = fileManager->getContents(Derived::DATA_FILE);
        vector<string> lines = split(content, '\n');

        for (const string& line : lines) {
            if (line.empty()) continue;
            try {
                T* item = ((Derived*)this)->parse(line);
                items.push_back(item);
            } catch (const runtime_error& e) {
                throw runtime_error(string(e.what()));
            }
        }

        return items;
    }

protected:
    FileManager* fileManager;

    DataParser() {
        fileManager = FileManager::getInstance();
    }

    /**
     * @brief Splits a string into a vector of strings based on a delimiter.
     * @param str The string to be split.
     * @param delimiter The character used to split the string.
     * @return A vector of strings resulting from the split operation.
     * @details This method is used to parse lines from the data file.
    */
    vector<string> split(const string& str, char delimiter) {
        vector<string> result;
        string current;

        for (char ch : str) {
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
};
