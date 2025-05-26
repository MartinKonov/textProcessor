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
    static DocumentRegister* getInstance();
    static void destroyInstance();

    void addDocument(string name);
    void removeDocument(string name);
    Document* getDocument(string name);
    void saveDocument(Document* document);
    void saveAsDocument(Document* document, const string newFilename);
    size_t getDocumentCount() const;


 private:
    DocumentRegister();
    DocumentRegister(const DocumentRegister&) = delete;
    DocumentRegister& operator=(const DocumentRegister&) = delete;
    ~DocumentRegister();

    bool docAlreadyLoaded(string name);

    static DocumentRegister* instance;
    vector<Document*> documents;
    DocumentParser* documentParser;

};