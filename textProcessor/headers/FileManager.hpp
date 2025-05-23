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

class FileManager {
public:
    void open(const string& filename);
    string getContents(const string& filename);
    void close(const string& filename);
    void save(const string& filename);
    void saveAs(const string& oldFilename, const string& newFilename);
    void setContent(const string& filename, const string& content);

private:
    vector<string> filenames;
    vector<string> contents;

    int findIndex(const std::string& filename);
};
