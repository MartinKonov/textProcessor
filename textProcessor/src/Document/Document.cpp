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

/**
 * @brief Assignment operator for Document class
 * 
 * This operator copies the contents of another Document into this one.
 * It first frees the existing resources and then copies the new data.
 * 
 * @param other The Document to copy from.
 * @return Document& Reference to the current Document object.
 */
Document& Document::operator=(const Document& other)
{
    if(this != &other)
    {
        freeDocument();
        copyFrom(other);
    }
    return *this;
}

/**
 * @brief Compares the lines of this document with another document.
 * 
 * @param other The other document to compare with.
 * @return true if the lines are equal, false otherwise.
 */
bool Document::operator==(Document& other)
{
    return compareLinesTo(other);
}

/**
 * @brief Compares the lines of this document with another document.
 * 
 * @param other The other document to compare with.
 * @return true if the lines are not equal, false otherwise.
 */
bool Document::operator!=(Document& other)
{
    return !compareLinesTo(other);
}

/**
 * @brief Move constructor for Document class
 * 
 * This constructor transfers ownership of resources from the other Document to this one.
 * It also sets the lineCreator to the singleton instance.
 * 
 * @param other The Document to move from.
 */
Document::Document(Document&& other) : docName(std::move(other.docName)), hasChanged(other.hasChanged),
    lines(std::move(other.lines))
{

    this->lineCreator = LineCreator::getInstance();
    other.hasChanged = false;
    other.lineCreator = nullptr;
}

/**
 * @brief Move assignment operator for Document class
 * 
 * @param other The Document to move from.
 * @return Document& Reference to the current Document object.
 */
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

/**
 * @brief Copies the contents of another Document into this one.
 * 
 * @param other The Document to copy from.
 */
void Document::copyFrom(const Document& other)
{
    this->docName = other.docName;
    this->hasChanged = other.hasChanged;
    
    for(Line* line : other.lines) {
        this->lines.push_back(lineCreator->createLine(line->getLine()));
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
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
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
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }
    Line* newLine = LineCreator::getInstance()->createLine(line);
    lines.insert(lines.begin() + index, newLine);
    hasChanged = true;
}

/**
 * @brief Changes the content of a line at the specified index.
 * 
 * @param index The index of the line to change (1-based).
 * @param newContent The new content for the line.
 * @throws std::out_of_range if the index is out of range.
 */
void Document::changeLine(size_t index, string newContent)
{
    if (index >= lines.size())
    {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }
    Line* newLine = LineCreator::getInstance()->createLine(newContent);
    delete lines[index];
    lines[index] = newLine;
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
    vector<size_t> movableIndices;
    vector<Line*> movableLines;

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
    vector<size_t> movableIndices;
    vector<Line*> movableLines;

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

/**
 * @brief Converts the content of the document to uppercase.
 * 
 * This method converts all lines in the document to uppercase.
 */
void Document::toUpper() {
    for (Line* line : lines) {
        line->toUpper();
    }
    hasChanged = true;
}

/**
 * @brief Converts a range of lines in the document to uppercase.
 * 
 * @param startIndex The starting index of the range (inclusive).
 * @param endIndex The ending index of the range (exclusive).
 */
void Document::toUpper(size_t startIndex, size_t endIndex) {
    if (startIndex >= lines.size() || endIndex > lines.size() || startIndex >= endIndex) {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }
    for (size_t i = startIndex; i < endIndex; ++i) {
        lines[i]->toUpper();
    }
    hasChanged = true;
}

/**
 * @brief Converts the content of the document to lowercase.
 * 
 * This method converts all lines in the document to lowercase.
 */
void Document::toLower() {
    for (Line* line : lines) {
        line->toLower();
    }
    hasChanged = true;
}

/**
 * @brief Converts a range of lines in the document to lowercase.
 * 
 * @param startIndex The starting index of the range (inclusive).
 * @param endIndex The ending index of the range (exclusive).
 */
void Document::toLower(size_t startIndex, size_t endIndex) {
    if (startIndex >= lines.size() || endIndex > lines.size() || startIndex >= endIndex) {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }
    for (size_t i = startIndex; i < endIndex; ++i) {
        lines[i]->toLower();
    }
    hasChanged = true;
}

/**
 * @brief Trims trailing spaces from all lines in the document.
 * 
 * This method removes any trailing spaces from each line in the document.
 */
void Document::trimTrailing() {
    for (Line* line : lines) {
        line->trimTrailing();
    }
    hasChanged = true;
}

/**
 * @brief Trims trailing spaces from lines in the document in a specified range.
 * @param startIndex The starting index of the range (inclusive).
 * @param endIndex The ending index of the range (exclusive).
 */
void Document::trimTrailing(size_t startIndex, size_t endIndex) {
    if (startIndex >= lines.size() || endIndex > lines.size() || startIndex >= endIndex) {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }
    for (size_t i = startIndex; i < endIndex; ++i) {
        lines[i]->trimTrailing();
    }
    hasChanged = true;
}

/**
 * @brief Trims leading spaces from all lines in the document.
 * 
 * This method removes any leading spaces from each line in the document.
 */
void Document::trimLeading() {
    for (Line* line : lines) {
        line->trimLeading();
    }
    hasChanged = true;
}

/**
 * @brief Trims leading spaces from lines in the document in a specified range. 
 * @param startIndex The starting index of the range (inclusive).
 * @param endIndex The ending index of the range (exclusive).
 */
void Document::trimLeading(size_t startIndex, size_t endIndex) {
    if (startIndex >= lines.size() || endIndex > lines.size() || startIndex >= endIndex) {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }
    for (size_t i = startIndex; i < endIndex; ++i) {
        lines[i]->trimLeading();
    }
    hasChanged = true;
}

/**
 * @brief Scrambles the content of the document.
 *
 * This method randomly shuffles lines of the document.
 */
void Document::scramble() {
    random_device rd;
    mt19937 g(rd());
    shuffle(lines.begin(), lines.end(), g);
    hasChanged = true;
}

/**
 * @brief Scrambles the content of a specified range of lines in the document.
 * 
 * @param startIndex The starting index of the range (inclusive).
 * @param endIndex The ending index of the range (exclusive).
 */
void Document::scramble(size_t startIndex, size_t endIndex) {
    if (startIndex >= lines.size() || endIndex > lines.size() || startIndex >= endIndex) {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(lines.begin() + startIndex, lines.begin() + endIndex, g);
    hasChanged = true;
}


/**
 * @brief Removes duplicate lines from the document.
 * 
 * This method removes duplicate lines from the document.
 */
void Document::removeRepeats() {

    for(int i = 0; i < lines.size(); ++i) {
        for(int j = i + 1; j < lines.size(); ++j) {
            if(*lines[i] == *lines[j]) {
                removeLine(j);
                --j;
            }
        }
    }
    hasChanged = true;
}

/**
 * @brief Removes duplicate lines from a specified range in the document.
 * 
 * @param startIndex The starting index of the range (inclusive).
 * @param endIndex The ending index of the range (inclusive).
 */
void Document::removeRepeats(size_t startIndex, size_t endIndex) {
    if (startIndex >= lines.size() || endIndex > lines.size() || startIndex >= endIndex) {
        throw out_of_range(ERROR_INDEX_OUT_OF_RANGE);
    }

    for (size_t i = startIndex; i < endIndex; ++i) {
        for (size_t j = i + 1; j < endIndex; ++j) {
            if (*lines[i] == *lines[j]) {
                removeLine(j);
                --j;
            }
        }
    }
    hasChanged = true;
}