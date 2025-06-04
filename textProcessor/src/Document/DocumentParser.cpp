#include "../../headers/Document/DocumentParser.hpp"

/**
 * @file DocumentParser.cpp
 * @author MK
 * @brief A class to parse documents.
 * @version 0.1
 * @date 2025-05-18
 */

DocumentParser::DocumentParser(FileManager* filemanager, LineCreator* lineCreator) {
    this->fileManager = filemanager;
    this->lineCreator = lineCreator;
}

/**
 * @brief Saves the document if it has changed.
 * 
 * @param document The document to save.
 * @throws runtime_error if the file cannot be saved.
 */
void DocumentParser::save(Document *document)
{
    if(!document) {
        throw runtime_error("DocumentParser::save: Invalid document passed");
    }
    if (!document->getHasChanged()) {
        return;
    }
    fileManager->setContent(document->getDocName(), document->getContents());
    document->setHasChanged(false);
    try {
        fileManager->save(document->getDocName());
    } catch (const runtime_error& e) {
        throw runtime_error("DocumentParser::save: " + string(e.what()));
    }
}

/**
 * @brief Loads a document from a file.
 * 
 * @param filename The name of the file to load.
 * @return Document* A pointer to the loaded document.
 * @throws runtime_error if the file cannot be loaded.
 */
Document* DocumentParser::load(const string filename)
{
    string content;
    try {
        fileManager->loadFile(filename);
        content = fileManager->getContents(filename);
    } catch (const runtime_error& e) {
        throw runtime_error("DocumentParser::load: " + string(e.what()));
    }
    Document* document = parseDocument(content, filename);
    return document;
}

/**
 * @brief Saves the document with a new filename.
 * 
 * @param document The document to save.
 * @param newFilename The new filename to save the document as.
 * @throws runtime_error if the file cannot be saved.
 */
void DocumentParser::saveAsDocument(Document* document, const string newFilename)
{
    if(!document) {
        throw runtime_error("DocumentParser::saveAsDocument: Invalid document passed");
    }
    try{
        fileManager->saveAs(document->getDocName(), newFilename);
    } catch (const runtime_error& e) {
        throw runtime_error("DocumentParser::saveAsDocument: " + string(e.what()));
    }
}

/**
 * @brief Unloads a document by closing the file.
 * 
 * @param document The document to unload.
 */
void DocumentParser::unloadDocument(Document* document)
{
    if(!document) {
        throw runtime_error("DocumentParser::unloadDocument: Invalid document passed");
    }
    string filename = document->getDocName();
    fileManager->close(filename);
}

/**
 * @brief Parses the content of a document into a Document object.
 * 
 * @param content The content of the document.
 * @param filename The name of the file.
 * @return Document* A pointer to the parsed Document object.
 */
Document* DocumentParser::parseDocument(const string content, const string filename)
{
    vector<Line*> lines;
    size_t start = 0;
    size_t end = 0;

    while (end != string::npos) {
        end = content.find('\n', start);
        string line;

        if (end != string::npos) {
            line = content.substr(start, end - start);
            start = end + 1;
        } else {
            line = content.substr(start);
        }

        Line* parsedLine = lineCreator->createLine(line);
        lines.push_back(parsedLine);
    }

    return new Document(filename, lines);
}
