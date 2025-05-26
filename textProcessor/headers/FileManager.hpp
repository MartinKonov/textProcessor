/**
 * @file FileManager.hpp
 * @author MK
 * @brief A class to manage file operations such as opening, reading, writing, and closing files.
 * @version 0.1
 * @date 2025-05-18
 */

#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

using std::vector;
using std::string;
using std::runtime_error;
using std::ofstream;
using std::ifstream;

/**
 * @brief A class to manage file operations such as opening, reading, writing, and closing files.
 * 
 */
class FileManager {
public:
    static FileManager* getInstance();

    void loadFile(const string& filename);
    string getContents(const string& filename);
    void close(const string& filename);
    void save(const string& filename);
    void saveAs(const string& oldFilename, const string& newFilename);
    void setContent(const string& filename, const string& content);

private:
    FileManager() = default;
    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

    static FileManager* instance;

    vector<string> filenames;
    vector<string> contents;

    int findIndex(const std::string& filename);
    ifstream openFile(const string& filename);
};
