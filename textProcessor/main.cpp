#include <iostream>
#include <fstream>
#include <string>
#include "../headers/Commands/CommandRegister.hpp"
#include "../headers/Commands/AddLineCommand.hpp"
#include "../headers/Commands/SaveCommand.hpp"
#include "../headers/CommandsCLI/SaveCommandCLI.hpp"
#include "../headers/Commands/SaveAsCommand.hpp"
#include "../headers/CommandsCLI/SaveAsCommandCLI.hpp"
#include "../headers/Commands/LoadDocumentCommand.hpp"
#include "../headers/CommandsCLI/LoadDocumentCommandCLI.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


string loadFileContent(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filePath);
    }

    string content, line;
    while (getline(file, line)) {
        content += line + '\n';
    }

    return content;
}

int main() {
    try {
        CommandRegister* commandRegister = new CommandRegister();
        FileManager* fm = FileManager::getInstance();
        LineCreator* lc = LineCreator::getInstance();
        DocumentParser* dp = new DocumentParser(fm, lc);
        DocumentRegister* dr = new DocumentRegister(dp);
        ActiveDocument* ad = new ActiveDocument(dr);
        AddLineCommandCLI* addLineCommandCLI = new AddLineCommandCLI();
        SaveCommandCLI* saveCommandCLI = new SaveCommandCLI();
        SaveAsCommandCLI* saveAsCommandCLI = new SaveAsCommandCLI();
        LoadDocumentCommandCLI* loadDocumentCommandCLI = new LoadDocumentCommandCLI();

        AddLineCommand* addLineCommand = new AddLineCommand(addLineCommandCLI, ad);
        SaveCommand* saveCommand = new SaveCommand(ad, saveCommandCLI, dr);
        SaveAsCommand* saveAsCommand = new SaveAsCommand(ad, saveAsCommandCLI, dr);   
        LoadDocumentCommand* loadDocumentCommand = new LoadDocumentCommand(loadDocumentCommandCLI, dr);           

        // Register the command
        commandRegister->registerCommand(addLineCommand);
        commandRegister->registerCommand(saveCommand);
        commandRegister->registerCommand(saveAsCommand);
        commandRegister->registerCommand(loadDocumentCommand);

        cout << "Commands:\n" << commandRegister->showAllCommands() << endl;

        commandRegister->executeCommand(4);

        // Execute the command
        // commandRegister->executeCommand(1); // Assuming this is the index of the AddLineCommand

        // cout << ad->getActiveDocument()->getContents() << endl;

        // commandRegister->executeCommand(3);

        // cout << ad->getActiveDocument()->getContents() << endl;

    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
