/**
 * @file Document.hpp
 * @author MK
 * @brief A class to represent a document containing multiple lines.
 * @version 0.1
 * @date 2025-05-18
 */
#pragma once
#include "../Lines/Line.hpp"
#include "../Lines/LineCreator.hpp"
#include "../../dataFiles/CommonErrors.hpp"
#include <vector>
#include <random>
#include <algorithm>

using std::vector;
using std::string;
using std::ostream;
using std::runtime_error;
using std::out_of_range;
using std::random_device;
using std::mt19937;
using std::shuffle;


/**
 * @brief A class to represent a document containing multiple lines.
 * 
 * The Document class manages a collection of Line objects, allowing for operations such as adding, removing,
 * and sorting lines, as well as tracking changes to the document.
 */
class Document {
 public:
    Document();
    Document(string name, vector<Line*> lines);
    ~Document();
    Document(const Document& other);
    Document& operator=(const Document& other);
    Document(Document&& other);
    Document& operator=(Document&& other);

    bool operator==(Document& other);
    bool operator!=(Document& other);

    bool getHasChanged();
    void setHasChanged(bool changed);
    size_t getNumSymbols();
    void removeLine(size_t index);
    void addLine(string line);
    void insertLine(size_t index, string line);
    void changeLine(size_t index, string newContent);
    string getDocName();
    void setDocName(string name);
    string getContents();
    string toString();
    size_t getNumLines();
    
    void sort();
    void sort(size_t startIndex, size_t endIndex);
    void toUpper();
    void toUpper(size_t startIndex, size_t endIndex);
    void toLower();
    void toLower(size_t startIndex, size_t endIndex);
    void trimTrailing();
    void trimTrailing(size_t startIndex, size_t endIndex);
    void trimLeading();
    void trimLeading(size_t startIndex, size_t endIndex);
    void scramble();
    void scramble(size_t startIndex, size_t endIndex);
    void removeRepeats();
    void removeRepeats(size_t startIndex, size_t endIndex);
    // TODO while the commands are being made
    
    friend ostream& operator<<(ostream& os, Document& document);
 private:
    void collectMovableLines(vector<Line*>& movableLines, vector<size_t>& movableIndices, size_t startIndex, size_t endIndex);
    bool sortMovableLines(vector<Line*>& movableLines, vector<size_t>& movableIndices);
    void copyFrom(const Document& other);
    void freeDocument();
    bool compareLinesTo(Document& other);
    string docName;
    bool hasChanged;
    LineCreator* lineCreator;
    vector<Line*> lines;
};
