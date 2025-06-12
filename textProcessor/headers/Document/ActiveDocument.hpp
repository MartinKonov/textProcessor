/**
 * @file ActiveDocument.hpp
 * @author MK
 * @brief A singleton class to manage the current active document in the text processor.
 * @version 0.1
 * @date 2025-05-18
 */

#pragma once
#include "Document.hpp"
#include "DocumentRegister.hpp"


class ActiveDocument {
 public:
    ActiveDocument() = delete; // need documentRegister injected
    ActiveDocument(DocumentRegister* documentRegister,Document* document = nullptr);
    ~ActiveDocument() = default;   

    void setActiveDocument(string documentName);
    void removeActiveDocument();
    Document* getActiveDocument() const;    
    
 private:
    Document* activeDocument;
    DocumentRegister* documentRegister;
};