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
#include <vector>

using namespace std;

class Document {
 public:
    Document();
    Document(string name, vector<Line*> lines);
    ~Document();
    Document(Document& other);
    Document& operator=(Document& other);
    Document(Document&& other);
    Document& operator=(Document&& other);

    bool getHasChanged();
    void setHasChanged(bool changed);
    size_t getNumSymbols();
    void removeLine(size_t index);
    void addLine(string line);
    void insertLine(size_t index, string line);
    string getDocName();
    void setDocName(string name);
    string getContents();
    string toString();
    size_t getNumLines();
    
    void sort();
    //void sort(Block)
    // TODO while the commands are being made
    
    friend ostream& operator<<(ostream& os, Document& document);
 private:
    void copyFrom(Document& other);
    void freeDocument();
    string docName;
    bool hasChanged;
    LineCreator* lineCreator;
    vector<Line*> lines;
};
