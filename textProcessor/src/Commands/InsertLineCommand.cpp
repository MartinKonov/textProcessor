#include "../../headers/Commands/InsertLineCommand.hpp"

/**
 * @file InsertLineCommand.cpp
 * @author MK
 * @brief A command to insert a line into the active document in the text processor application.
 */

InsertLineCommand::InsertLineCommand(InsertLineCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->previousDocument = nullptr;
}

/**
 * @brief Destroys the previous document object.
 */
InsertLineCommand::~InsertLineCommand() {
    delete previousDocument;
    previousDocument = nullptr;
}

/**
 * @brief Returns the name of the command.
 * 
 * This method provides the name of the command, which is used for display purposes in the CLI.
 * 
 * @return string The name of the command.
 */
string InsertLineCommand::getName() const {
    return INSERT_LINE_COMMAND_NAME;
}

void InsertLineCommand::execute() {
    Document* doc = activeDocument->getActiveDocument();
    if (!doc) {
        cli->noActiveDocumentSet();
        return;
    }

    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }

    previousDocument = new Document(*doc);

    cli->showDocumentWithIndices(doc->toString());
    string lineToInsert = cli->getLineToInsert();
    int lineNumber;
    try{
        lineNumber = cli->getLineNumberToInsert();
    } catch (const runtime_error& e) {
        cli->error(e.what());
        return;
    }

    try {
        doc->insertLine(lineNumber - 1, lineToInsert);
        cli->success();
    } catch (const out_of_range& e) {
        cli->error("Index out of range: " + string(e.what()));
    }
}

/**
 * @brief Undoes the last executed command of inserting a line.
 * 
 * This method restores the previous state of the document before the line was inserted.
 */
void InsertLineCommand::undo() {
    if (!previousDocument) {
        cli->error("No previous document state to restore.");
        return;
    }
    
    Document* doc = activeDocument->getActiveDocument();
    if (!doc) {
        cli->error("No active document set.");
        return;
    }

    if(*doc == *previousDocument) {
        cli->error("No changes to undo.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(doc->getDocName() != previousDocument->getDocName()) {
        cli->error("Active document has changed since the last command was executed.");
        return;
    }

    *doc = *previousDocument;
    delete previousDocument;
    previousDocument = nullptr;

    cli->successUndo();
}