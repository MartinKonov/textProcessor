/**
 * @file ActiveDocument.cpp
 * @author MK
 * @brief A singleton class to manage the current active document in the text processor.
 *  @version 0.1
 * @date 2025-05-24
 */

#include "../../headers/Document/ActiveDocument.hpp"


ActiveDocument* ActiveDocument::instance = nullptr;

ActiveDocument::ActiveDocument()
{
    this->documentRegister = DocumentRegister::getInstance();
    this->activeDocument = nullptr;
}

/**
 * @brief Returns the singleton instance of ActiveDocument.
 * 
 * @return ActiveDocument* The singleton instance of ActiveDocument.
 */
ActiveDocument* ActiveDocument::getInstance()
{
    if (instance == nullptr) {
        instance = new ActiveDocument();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of ActiveDocument.
 * 
 * This method deletes the instance of ActiveDocument and sets it to nullptr.
 */
void ActiveDocument::destroyInstance()
{
    delete instance;
    instance = nullptr;
}

/**
 * @brief Destructor for ActiveDocument.
 * 
 * This destructor does not free any dynamic memory, as DocumentRegister is a singleton
 * and is managed separately.
 */
ActiveDocument::~ActiveDocument()
{
    // No dynamic memory to free, as DocumentRegister is a singleton
}

/**
 * @brief Sets the active document.
 * 
 * @param documentName The name of the document to set as active.
 * @note This method also adds the document to the DocumentRegister.
 * @throws std::runtime_error if the DocumentRegister instance is not initialized.
 */
void ActiveDocument::setActiveDocument(string documentName) {    
    Document* doc;
    
    try{
        doc = documentRegister->getDocument(documentName);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("ActiveDocument::setActiveDocument: " + string(e.what()));
    }
    activeDocument = doc;
}

/**
 * @brief Returns the currently active document.
 * 
 * @return Document* A pointer to the active document.
 */
Document *ActiveDocument::getActiveDocument() const
{
    return activeDocument;
}