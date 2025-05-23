#include "../headers/FileManager.hpp"


int FileManager::findIndex(const string& filename) {
    for (size_t i = 0; i < filenames.size(); ++i) {
        if (filenames[i] == filename) {
            return (int)i;
        }
    }
    return -1;
}

void FileManager::open(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    string line;
    string content;
    while (getline(file, line)) {
        content += line + '\n';
    }

    int index = findIndex(filename);
    if (index == -1) {
        filenames.push_back(filename);
        contents.push_back(content);
    } else {
        contents[index] = content;
    }

    file.close();
}

string FileManager::getContents(const string& filename) {
    int index = findIndex(filename);
    if (index == -1) {
        throw runtime_error("File not loaded: " + filename);
    }
    return contents[index];
}

void FileManager::close(const string& filename) {
    int index = findIndex(filename);
    if (index != -1) {
        filenames.erase(filenames.begin() + index);
        contents.erase(contents.begin() + index);
    }
}

void FileManager::save(const string& filename) {
    int index = findIndex(filename);
    if (index == -1) {
        throw runtime_error("File not loaded: " + filename);
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file to save: " + filename);
    }

    file << contents[index];
    file.close();
}

void FileManager::saveAs(const string& oldFilename, const string& newFilename) {
    int index = findIndex(oldFilename);
    if (index == -1) {
        throw runtime_error("File not loaded: " + oldFilename);
    }

    ofstream file(newFilename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file to save as: " + newFilename);
    }

    file << contents[index];
    file.close();
}

void FileManager::setContent(const string& filename, const string& content) {
    int index = findIndex(filename);
    if (index == -1) {
        filenames.push_back(filename);
        contents.push_back(content);
    } else {
        contents[index] = content;
    }
}
