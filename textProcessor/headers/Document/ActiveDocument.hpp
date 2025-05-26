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
    static ActiveDocument* getInstance(); 
    static void destroyInstance();
    
    void setActiveDocument(string documentName);
    Document* getActiveDocument() const;    
    
 private:
    ActiveDocument();
    ActiveDocument(const ActiveDocument&) = delete;
    ActiveDocument& operator=(const ActiveDocument&) = delete;
    ~ActiveDocument();
    
    static ActiveDocument* instance;

    Document* activeDocument;
    DocumentRegister* documentRegister;
};