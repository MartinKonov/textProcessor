#include "../../headers/Document/DocumentRegister.hpp"

/**
 * @file DocumentRegister.cpp
 * @author MK
 * @brief A singleton class to manage a collection of documents.
 * @version 0.1
 * @date 2025-05-18
 */

DocumentRegister* DocumentRegister::instance = nullptr;

DocumentRegister::DocumentRegister() {
    this->documentParser = DocumentParser::getInstance();
}


/**
 * @brief Destructor for DocumentRegister.
 * 
 * This destructor cleans up all dynamically allocated Document objects and unloads them using the DocumentParser.
 */
DocumentRegister::~DocumentRegister() {
    for(auto & document : documents) {
        documentParser->unloadDocument(document);
        delete document;
    }
    documents.clear();
}

/**
 * @brief Returns the singleton instance of DocumentRegister.
 * @param documentParser The DocumentParser instance to use for loading documents.
 * @return DocumentRegister* The singleton instance of DocumentRegister.
 */
DocumentRegister *DocumentRegister::getInstance()
{
    if (instance == nullptr) {
        instance = new DocumentRegister();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of DocumentRegister.
 * 
 * This method deletes the instance of DocumentRegister and sets it to nullptr.
 */
void DocumentRegister::destroyInstance()
{
    delete instance;
    instance = nullptr;
} 

/**
   * @brief Adds a document to the register by loading it using the DocumentParser.
   * @param name The name of the document to add.
   * @throws std::runtime_error if the document cannot be loaded.
   * @note The document is loaded using the DocumentParser's load method, which may throw an exception if the file cannot be read or parsed.
   */
void DocumentRegister::addDocument(string name) {
    if(isDocumentLoaded(name)) {
        return;
    }
    Document* newDocument;
    try {
        newDocument = documentParser->load(name);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("DocumentRegister::addDocument: " + string(e.what())); 
    }
    documents.push_back(newDocument);
}


/**
 * @brief Removes a document from the register by its index.
 * @param index The index of the document to remove.
 * @throws std::out_of_range if the index is out of range.
 */
void DocumentRegister::removeDocument(string name)
{
    if(isDocumentLoaded(name) == false) {
        return;
    }
    
    for(int i = 0; i < documents.size(); i++) {
        if (documents[i]->getDocName() == name) {
            documentParser->unloadDocument(documents[i]);
            delete documents[i];
            documents.erase(documents.begin() + i);
            return;
        }
    }
}

/**
 * @brief Returns true if a document with the given name is loaded in the register.
 * @param name The name of the document to check.
 * @return bool True if the document is loaded, false otherwise.
 */
bool DocumentRegister::isDocumentLoaded(string name)
{
    for (const auto& document : documents) {
        if (document->getDocName() == name) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Retrieves a document from the register by its name.
 * @param name The name of the document to retrieve.
 * @return Document* A pointer to the document if found.
 * @throws runtime_error if the document is not found.
 */
Document *DocumentRegister::getDocument(string name)
{
    for (auto& document : documents) {
        if (document->getDocName() == name) {
            return document;
        }
    }
    throw std::runtime_error("DocumentRegister::getDocument: Document not found");
}

/**
 * @brief Saves a document if it has changed.
 * @param document The document to save.
 * @throws std::runtime_error if the document cannot be saved.
 */
void DocumentRegister::saveDocument(Document *document)
{
    if (!document->getHasChanged()) {
        return;
    }
    try {
        documentParser->save(document);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("DocumentRegister::saveDocument: " + string(e.what()));
    }
}

/**
 * @brief Saves a document with a new filename.
 * @param document The document to save.
 * @param newFilename The new filename to save the document as.
 * @throws std::runtime_error if the document cannot be saved.
 */
void DocumentRegister::saveAsDocument(Document* document, const string newFilename)
{
    try {
        documentParser->saveAsDocument(document, newFilename);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("DocumentRegister::saveAsDocument: " + string(e.what()));
    }
}

