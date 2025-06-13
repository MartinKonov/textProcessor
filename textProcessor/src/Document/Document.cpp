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
    freeDocument();
}

/**
 * @brief Copy constructor for Document class
 */
Document::Document(const Document& other)
{
    copyFrom(other);
}

Document& Document::operator=(const Document& other)
{
    if(this != &other)
    {
        freeDocument();
        copyFrom(other);
    }
    return *this;
}

bool Document::operator==(Document& other)
{
    return compareLinesTo(other);
}

bool Document::operator!=(Document& other)
{
    return !compareLinesTo(other);
}

Document::Document(Document&& other) : docName(std::move(other.docName)), hasChanged(other.hasChanged),
    lines(std::move(other.lines))
{

    this->lineCreator = LineCreator::getInstance();
    other.hasChanged = false;
    other.lineCreator = nullptr;
}


Document& Document::operator=(Document&& other) {
    if (this != &other) {
        freeDocument();

        docName = std::move(other.docName);
        hasChanged = other.hasChanged;
        lines = std::move(other.lines);
        lineCreator = LineCreator::getInstance();
        other.hasChanged = false;
    }
    return *this;
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

void Document::copyFrom(const Document& other)
{
    this->docName = other.docName;
    this->hasChanged = other.hasChanged;
    
    for(Line* line : other.lines) {
        this->lines.push_back(new Line(*line));
    }

}


/**
 * @brief Deletes the allocated memory in Document class
 */
void Document::freeDocument()
{    
    for (Line *line : lines)
    {
        delete line;
    }
    lines.clear();
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
 * @brief Returns the number of lines in the document.
 * 
 * @return size_t The number of lines in the document.
 */
size_t Document::getNumLines()
{
    return lines.size();
}

/**
 * @brief Compares the lines of this document with another document.
 * 
 * @param other The other document to compare with.
 * @return true if the lines are equal, false otherwise.
 */
bool Document::compareLinesTo(Document& other)
{
    if(this->lines.size() != other.lines.size())
    {
        return false;
    }

    for(int i = 0; i < lines.size(); i++)
    {
        if(this->lines[i] != other.lines[i])
        {
            return false;
        }
    }
    return true;
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

void Document::sort() {
    std::vector<size_t> movableIndices;
    std::vector<Line*> movableLines;

    collectMovableLines(movableLines, movableIndices, 0, lines.size());
    bool lineHasMoved = sortMovableLines(movableLines, movableIndices);

    if(lineHasMoved){
        hasChanged = true;
    }
}

/**
 * @brief Collects movable lines and their indices from the document.
 * 
 * @param movableLines The vector to store movable lines.
 * @param movableIndices The vector to store indices of movable lines.
 * @param startIndex The starting index for collection.
 * @param endIndex The ending index for collection.
 */
void Document::collectMovableLines(vector<Line*>& movableLines, vector<size_t>& movableIndices, size_t startIndex, size_t endIndex) {

    for (size_t i = startIndex; i < endIndex; ++i) {
        if (lines[i]->isMovableInSort()) {
            movableIndices.push_back(i);
            movableLines.push_back(lines[i]);
        }
    }
}

/**
 * @brief Sorts the lines in the document within a specified range.
 * 
 * @param startIndex The starting index for sorting (inclusive).
 * @param endIndex The ending index for sorting (exclusive).
 */
void Document::sort(size_t startIndex, size_t endIndex) {
    std::vector<size_t> movableIndices;
    std::vector<Line*> movableLines;

    collectMovableLines(movableLines, movableIndices, startIndex, endIndex);
    bool lineHasMoved = sortMovableLines(movableLines, movableIndices);

    if(lineHasMoved){
        hasChanged = true;
    }
}

/**
 * @brief Sorts the movable lines and updates the document with the sorted lines.
 * 
 * @param movableLines The vector of movable lines to be sorted.
 * @param movableIndices The vector of indices corresponding to the movable lines.
 * @return true if any line has moved, false otherwise.
 */
bool Document::sortMovableLines(vector<Line*>& movableLines, vector<size_t>& movableIndices) {
    bool lineHasMoved = false;
    for (size_t i = 0; i < movableLines.size(); ++i) {
        for (size_t j = 0; j < movableLines.size() - 1 - i; ++j) {
            if (*movableLines[j + 1] < *movableLines[j]) {
                Line* temp = movableLines[j];
                movableLines[j] = movableLines[j + 1];
                movableLines[j + 1] = temp;
                lineHasMoved = true;
            }
        }
    }

    for (size_t i = 0; i < movableIndices.size(); ++i) {
        lines[movableIndices[i]] = movableLines[i];
    }

    return lineHasMoved;
}