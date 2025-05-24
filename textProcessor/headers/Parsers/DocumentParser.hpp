/**
 * @file DocumentParser.hpp
 * @author MK
 * @brief A class to parse documents.
 * @version 0.1
 * @date 2025-05-18
 */
#pragma once
#include "../FileManager.hpp"
#include "../Documents/Document.hpp"
#include "../Lines/Line.hpp"
#include "../Lines/LineCreator.hpp"

class DocumentParser
{
 public:
    DocumentParser(FileManager* fileManager);
    void save(Document* document);
    Document* load(const string filename); // gets the string from the file manager and makes a document with parseDocument
    void saveAsDocument(Document* document, const string newFilename);
    void unloadDocument(Document* document);

 private:
    FileManager* fileManager;
    LineCreator* lineCreator;

    void parseLine(const std::string& line);
    Document* parseDocument(const std::string content, const string filename);

};