/**
 * @file FileManager.cpp
 * @author MK
 * @brief A singleton class to manage file operations such as opening, reading, writing, and closing files.
 * @version 0.1
 * @date 2025-05-18
 */
#include "../headers/FileManager.hpp"


FileManager* FileManager::instance = nullptr;

/**
 * @brief Returns the singleton instance of FileManager.
 * 
 * @return FileManager* The singleton instance of FileManager.
 */
FileManager* FileManager::getInstance() {
    if (instance == nullptr) {
        instance = new FileManager();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of FileManager.
 */
void FileManager::destroyInstance() {
    delete instance;
    instance = nullptr;
}

/**
 * @brief Destructor for the FileManager class.
 * Cleans up the instance and its resources.
 */
FileManager::~FileManager() {
    filenames.clear();
    contents.clear();
    instance = nullptr;
}

/**
 * @brief Finds the index of a file in the filenames vector.
 */
int FileManager::findIndex(const string& filename) {
    for (size_t i = 0; i < filenames.size(); ++i) {
        if (filenames[i] == filename) {
            return (int)i;
        }
    }
    return -1;
}

/**
 * @brief Opens a file and reads its contents.
 *
 * @param filename The name of the file to open.
 * @throws runtime_error if the file cannot be opened.
*/
void FileManager::loadFile(const string& filename) {
    
    int index = findIndex(filename);
    if (index != -1) {
        return;
    }

    ifstream file;
    try {
        file = openFile(filename);
    } catch (const runtime_error& e) {
        throw runtime_error(string(ERROR_OPENING_FILE) + " " + filename);
    }

    string line = "";
    string content = "";
    while (getline(file, line)) {
        content += line + '\n';
    }
    
    if (!content.empty() && content.back() == '\n') {
        content.pop_back();
    }


    setContent(filename, content);
    file.close();
}

/**
 * @brief Opens a file and returns the ifstream object.
 * 
 * @param filename The name of the file to open.
 * @return ifstream The opened file stream.
 * @throws runtime_error if the file cannot be opened.
 */
ifstream FileManager::openFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error(string(ERROR_OPENING_FILE) + " " + filename);
    }
    return file;
} 

/**
 * @brief Gets the contents of a file.
 * 
 * @param filename The name of the file to get contents from.
 * @return string The contents of the file.
 * @throws runtime_error if the file is not loaded.
 */
string FileManager::getContents(const string& filename) {
    int index = findIndex(filename);
    if (index == -1) {
        throw runtime_error(string(ERROR_FILE_NOT_LOADED) + " " + filename);
    }
    return contents[index];
}

/**
 * @brief Closes a file and removes it from the loaded files.
 * 
 * @param filename The name of the file to close.
 */
void FileManager::close(const string& filename) {
    int index = findIndex(filename);
    if (index != -1) {
        filenames.erase(filenames.begin() + index);
        contents.erase(contents.begin() + index);
    }
}

/**
 * @brief Saves the contents of a file.
 * 
 * @param filename The name of the file to save.
 * @throws runtime_error if the file is not loaded or cannot be opened.
 */
void FileManager::save(const string& filename) {
    int index = findIndex(filename);
    if (index == -1) {
        throw runtime_error(string(ERROR_FILE_NOT_LOADED) + " " + filename);
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error(string(ERROR_OPENING_FILE) + " " + filename);
    }

    file << contents[index];
    file.close();
}

/**
 * @brief Saves the contents of a file with a new name.
 * 
 * @param oldFilename The name of the file to save from.
 * @param newFilename The name of the file to save to.
 * @throws runtime_error if the old file is not loaded or the new file cannot be opened.
 */
void FileManager::saveAs(const string& oldFilename, const string& newFilename) {
    int index = findIndex(oldFilename);
    if (index == -1) {
        throw runtime_error(string(ERROR_FILE_NOT_LOADED) + " " + oldFilename);
    }

    ofstream file(newFilename);
    if (!file.is_open()) {
        throw runtime_error(string(ERROR_OPENING_FILE) + " " + newFilename);
    }

    file << contents[index];
    file.close();
}

/**
 * @brief Saves the contents of a file with a new name and new content.
 */
void FileManager::saveAs(const string& oldFilename, const string& newFilename, string newContent)
{
    int index = findIndex(oldFilename);
    if (index == -1) {
        throw runtime_error(string(ERROR_FILE_NOT_LOADED) + " " + oldFilename);
    }

    ofstream file(newFilename);
    if (!file.is_open()) {
        throw runtime_error(string(ERROR_OPENING_FILE) + " " + newFilename);
    }
    setContent(newFilename, newContent);

    file << newContent;
    
    file.close();
}

/**
 * @brief Sets the content of a file.
 * 
 * @param filename The name of the file to set content for.
 * @param content The content to set.
 */
void FileManager::setContent(const string& filename, const string& content) {
    int index = findIndex(filename);
    if (index == -1) {
        filenames.push_back(filename);
        contents.push_back(content);
    } else {
        contents[index] = content;
    }
}
