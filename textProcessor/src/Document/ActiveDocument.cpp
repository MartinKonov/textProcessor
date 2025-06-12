/**
 * @file ActiveDocument.cpp
 * @author MK
 * @brief A singleton class to manage the current active document in the text processor.
 *  @version 0.1
 * @date 2025-05-24
 */

#include "../../headers/Document/ActiveDocument.hpp"

ActiveDocument::ActiveDocument(DocumentRegister* documentRegister, Document* document)
{
    this->documentRegister = documentRegister;
    this->activeDocument = document;
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
    } catch (const runtime_error& e) {
        throw runtime_error("ActiveDocument::setActiveDocument: " + string(e.what()));
    }
    activeDocument = doc;
}

void ActiveDocument::removeActiveDocument() {
    if(activeDocument){
        activeDocument = nullptr;
    }
}
/**
 * @brief Returns the currently active document.
 * 
 * @return Document* A pointer to the active document.
 * @throws runtime_error if the active document hasn't been set yet
 */
Document *ActiveDocument::getActiveDocument() const
{
    if(!activeDocument) {
        return nullptr;
    }
    return activeDocument;
}