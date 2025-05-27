#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include "FileManager.hpp"

using std::string;
using std::vector;

template <typename Derived, typename T>
class DataParser {
public:
    void save(T* item) {
        string content = ((Derived*)this)->serialize(item);

        try {
            fileManager->loadFile(Derived::DATA_FILE);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("DataParser::save: " + string(e.what()));
        }

        string existingContent = fileManager->getContents(Derived::DATA_FILE);
        string newContent = existingContent + content;

        fileManager->setContent(Derived::DATA_FILE, newContent);

        try {
            fileManager->save(Derived::DATA_FILE);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("DataParser::save: " + string(e.what()));
        }
    }

    void save(const vector<T*>& items) {
        string content;
        for (T* item : items) {
            content += ((Derived*)this)->serialize(item);
        }

        try {
            fileManager->loadFile(Derived::DATA_FILE);
            fileManager->setContent(Derived::DATA_FILE, content);
            fileManager->save(Derived::DATA_FILE);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("DataParser::save (batch): " + string(e.what()));
        }
    }

    vector<T*> load() {
        vector<T*> items;
        try {
            fileManager->loadFile(Derived::DATA_FILE);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("DataParser::load: " + string(e.what()));
        }

        string content = fileManager->getContents(Derived::DATA_FILE);
        vector<string> lines = split(content, '\n');

        for (const string& line : lines) {
            if (line.empty()) continue;
            try {
                T* item = ((Derived*)this)->parse(line);
                items.push_back(item);
            } catch (const std::runtime_error& e) {
                throw std::runtime_error("DataParser::load: " + string(e.what()));
            }
        }

        return items;
    }

protected:
    FileManager* fileManager;

    DataParser() {
        fileManager = FileManager::getInstance();
    }

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
