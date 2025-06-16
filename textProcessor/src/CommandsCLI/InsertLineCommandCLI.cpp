#include "../../headers/CommandsCLI/InsertLineCommandCLI.hpp"

/**
 * @file InsertLineCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the InsertLineCommand.
 */

 /**
  * @brief Displays a success message when a line is inserted.
  */
void InsertLineCommandCLI::success() {
    cout << "Line inserted successfully." << endl;
}

/**
 * @brief Displays the document contents with line indices.
 * 
 * @param document The contents of the document to display.
 */
void InsertLineCommandCLI::showDocumentWithIndices(string document) {
    cout << document << endl;
}

/**
 * @brief Displays a success message when an undo operation is successful.
 * 
 */
void InsertLineCommandCLI::successUndo() {
    cout << "Insert Line undo successful." << endl;
}

/**
 * @brief Displays an error message when no active document is set.
 */
string InsertLineCommandCLI::getLineToInsert() {
    cout << "Enter the line to insert:" << endl;
    string line;
    getline(cin, line);
    return line;
}

/**
 * @brief Prompts the user for the line number to insert at.
 * 
 * @return The line number as an integer.
 * @throws runtime_error if the input is not a valid integer.
 */
int InsertLineCommandCLI::getLineNumberToInsert() {
    cout << "Enter the line number to insert at:" << endl;
    string lineNumberStr;
    getline(cin, lineNumberStr);
    try {
        return stoi(lineNumberStr);
    } catch (const invalid_argument&) {
        throw runtime_error(ERROR_INVALID_LINE_NUMBER);
    }
}