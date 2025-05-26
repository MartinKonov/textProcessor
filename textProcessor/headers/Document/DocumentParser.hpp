/**
 * @file DocumentParser.hpp
 * @author MK
 * @brief A singleton class to parse documents.
 * @version 0.1
 * @date 2025-05-18
 */
#pragma once
#include "../FileManager.hpp"
#include "Document.hpp"
#include "../Lines/Line.hpp"
#include "../Lines/LineCreator.hpp"

class DocumentParser
{
 public:
    static DocumentParser* getInstance();
    static void destroyInstance();

    void save(Document* document);
    Document* load(const string filename); // gets the string from the file manager and makes a document with parseDocument
    void saveAsDocument(Document* document, const string newFilename);
    void unloadDocument(Document* document);
    
 private:
    DocumentParser();
    DocumentParser(const DocumentParser&) = delete;
    DocumentParser& operator=(const DocumentParser&) = delete;
    ~DocumentParser();

    static DocumentParser* instance;
    
    FileManager* fileManager;
    LineCreator* lineCreator;
    Document* parseDocument(const std::string content, const string filename);

};