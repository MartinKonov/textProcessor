#include "../../headers/Document/Document.hpp"

Document::Document()
{
    this->hasChanged = false;
}

/**
 * @brief Constructs a Document with a name and a vector of lines.
 * 
 * @param name The name of the document.
 * @param lines The lines in the document.
 */
Document::Document(string name, vector<Line *> lines)
{
    this->docName = name;
    this->lines = lines;
    this->hasChanged = false;
    this->lineCreator = LineCreator::getInstance();
}

/**
 * @brief Destructor for Document, cleans up the lines.
 */
Document::~Document()
{
    for (Line *line : lines)
    {
        delete line;
    }
}

/**
 * @brief Returns whether the document has changed.
 * 
 * @return true if the document has changed, false otherwise.
 */
bool Document::getHasChanged()
{
    return hasChanged;
}

/**
 * @brief Sets the changed status of the document.
 * 
 * @param changed The new changed status.
 */
void Document::setHasChanged(bool changed)
{
    hasChanged = changed;
}

/**
 * @brief Returns the total number of symbols in the document.
 * 
 * @return size_t The total number of symbols.
 */
size_t Document::getNumSymbols()
{
    size_t count = 0;
    for (Line* line : lines)
    {
        count += line->getSymbolCount();
    }
    return count;
}

/**
 * @brief Removes a line from the document at the specified index.
 * 
 * @param index The index of the line to remove (1-based).
 * @throws std::out_of_range if the index is out of range.
 */
void Document::removeLine(size_t index)
{
    if (index >= lines.size())
    {
        throw std::out_of_range("Document::removeLine: index out of range");
    }
    delete lines[index];
    lines.erase(lines.begin() + index);
    hasChanged = true;
}

/**
 * @brief Adds a new line to the document.
 * 
 * @param line The content of the new line.
 */
void Document::addLine(string line)
{
    Line* newLine = LineCreator::getInstance()->createLine(line);
    lines.push_back(newLine);
    hasChanged = true;
}

/**
 * @brief Inserts a new line at the specified index in the document.
 * 
 * @param index The index at which to insert the new line (1-based).
 * @param line The content of the new line.
 * @throws std::out_of_range if the index is out of range.
 */
void Document::insertLine(size_t index, string line)
{
    if (index > lines.size())
    {
        throw std::out_of_range("Document::insertLine: index out of range");
    }
    Line* newLine = LineCreator::getInstance()->createLine(line);
    lines.insert(lines.begin() + index, newLine);
    hasChanged = true;
}

/**
 * @brief Returns the name of the document.
 * 
 * @return string The name of the document.
 */
string Document::getDocName()
{
    return docName;
}

/**
 * @brief Sets the name of the document.
 * 
 * @param name The new name of the document.
 */
void Document::setDocName(string name)
{
    docName = name;
    hasChanged = true;
}

/**
 * @brief Returns the contents of the document as a single string.
 * 
 * @return string The contents of the document.
 */
string Document::getContents()
{
    string content;
    for (Line* line : lines)
    {
        content += line->getLine() + "\n";
    }
    return content;
}

/**
 * @brief Returns a string representation of the document, including line numbers.
 * 
 * @return string The string representation of the document.
 */
string Document::toString()
{
    string content;
    for (int i = 0; i < lines.size(); ++i)
    {
        Line* line = lines[i];
        content += std::to_string(i + 1) + ". " + line->getLine() + "\n";
    }
    return content;
}

/**
 * @brief Overloads the << operator to print the document's contents.
 * 
 * @param os The output stream.
 * @param document The document to print.
 * @return ostream& The output stream after printing the document.
 */
ostream& operator<<(ostream& os, Document& document)
{
    os << document.toString();
    return os;
}

void Document::sort()
{
    //TODO
}
