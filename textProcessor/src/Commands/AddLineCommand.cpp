#include "../../headers/Commands/AddLineCommand.hpp"

/**
 * @file AddLineCommand.cpp
 * @author MK
 * @brief A command to add a line to the end of the active document in the text processor application.
 */
AddLineCommand::AddLineCommand(AddLineCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->docBeforeExecution = nullptr;
}

/**
 * @brief Destructor for AddLineCommand.
 * It deletes the document before execution to free up memory.
 */
AddLineCommand::~AddLineCommand() {
    delete docBeforeExecution;
    docBeforeExecution = nullptr;
}

/**
 * @brief Executes the command to add a line to the active document.
 * If there is no active document, it shows an error message.
 * It also saves the state of the document before making changes for undo functionality.
 */
void AddLineCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        cli->activeDocumentError();
        return;
    }

    string line = cli->getLineInput();
    Document* currentActiveDocument = activeDocument->getActiveDocument();
    
    if(docBeforeExecution) {
        delete docBeforeExecution;
        docBeforeExecution = nullptr;
    }
    this->docBeforeExecution = new Document(*currentActiveDocument);

    currentActiveDocument->addLine(line);

    cli->success();
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string AddLineCommand::getName() const {
    return ADD_LINE_COMMAND_NAME;
}

/**
 * @brief Undoes the last executed command of adding a line.
 * It restores the document to its state before the command was executed.
 * If the active document has changed or if there is no document before execution, it shows an error message.
 */
void AddLineCommand::undo() 
{
    if(!docBeforeExecution){
        return;
    }

    string activeDocName = activeDocument->getActiveDocument()->getDocName();

    if(*activeDocument->getActiveDocument() == *docBeforeExecution)
    {
        cli->nothingChanged();
        delete docBeforeExecution;
        docBeforeExecution = nullptr;
        return;
    }

    if(activeDocName != docBeforeExecution->getDocName())
    {
        cli->error();
        delete docBeforeExecution;
        docBeforeExecution = nullptr;
        return;
    }

    if(*activeDocument->getActiveDocument() == *docBeforeExecution)
    {
        cli->nothingChanged();
    }

    *activeDocument->getActiveDocument() = *docBeforeExecution;
    delete docBeforeExecution;
    docBeforeExecution = nullptr;
}

void AddLineCommand::setDocBeforeExecution(Document* currentActiveDocument)
{
    if(this->docBeforeExecution)
    {
        delete docBeforeExecution;
    }

    this->docBeforeExecution = new Document(*currentActiveDocument);
}
