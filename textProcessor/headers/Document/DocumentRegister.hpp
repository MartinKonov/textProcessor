/**
 * DocumentRegister.hpp
 * @file DocumentRegister.hpp
 * @author MK
 *   @brief A singleton class to manage a collection of documents.
 * @version 0.1
 * @date 2025-05-18
 */

#pragma once
#include "Document.hpp"
#include "DocumentParser.hpp"


class DocumentRegister {

 public:
    DocumentRegister() = delete; //need to inject documentParser
    DocumentRegister(DocumentParser* documentParser);
    ~DocumentRegister();


    void addDocument(string name);
    void removeDocument(string name);
    Document* getDocument(string name);
    void saveDocument(Document* document);
    void saveAsDocument(Document* document, const string newFilename);
    size_t getDocumentCount() const;


 private:
    bool isDocumentLoaded(string name);
    
    vector<Document*> documents;
    DocumentParser* documentParser;

};