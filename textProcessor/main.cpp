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
#include "../headers/Commands/UnloadDocumentCommand.hpp"
#include "../headers/CommandsCLI/UnloadDocumentCommandCLI.hpp"
#include "../headers/Commands/SetActiveDocumentCommand.hpp"
#include "../headers/CommandsCLI/SetActiveDocumentCommandCLI.hpp"
#include "../headers/Commands/CreateBlockCommand.hpp"
#include "../headers/CommandsCLI/CreateBlockCommandCLI.hpp"
#include "../headers/Commands/RemoveBlockCommand.hpp"
#include "../headers/CommandsCLI/RemoveBlockCommandCLI.hpp"
#include "../headers/Commands/SetActiveBlockCommand.hpp"
#include "../headers/CommandsCLI/SetActiveBlockCommandCLI.hpp"
#include "../headers/Block/ActiveBlock.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


int main() {
    try {
        CommandRegister* commandRegister = new CommandRegister();
        FileManager* fm = FileManager::getInstance();
        LineCreator* lc = LineCreator::getInstance();
        DocumentParser* dp = new DocumentParser(fm, lc);
        DocumentRegister* dr = new DocumentRegister(dp);
        BlockRegister* br = BlockRegister::getInstance();
        ActiveDocument* ad = new ActiveDocument(dr);
        ActiveBlock* ab = new ActiveBlock(br);

        AddLineCommandCLI* addLineCommandCLI = new AddLineCommandCLI();
        SaveCommandCLI* saveCommandCLI = new SaveCommandCLI();
        SaveAsCommandCLI* saveAsCommandCLI = new SaveAsCommandCLI();
        LoadDocumentCommandCLI* loadDocumentCommandCLI = new LoadDocumentCommandCLI();
        UnloadDocumentCommandCLI* unloadDocumentCommandCLI = new UnloadDocumentCommandCLI();
        SetActiveDocumentCommandCLI* setActiveDocumentCommandCLI = new SetActiveDocumentCommandCLI();
        CreateBlockCommandCLI* createBlockCommandCLI = new CreateBlockCommandCLI();
        RemoveBlockCommandCLI* removeBlockCommandCLI = new RemoveBlockCommandCLI();
        SetActiveBlockCommandCLI* setActiveBlockCommandCLI = new SetActiveBlockCommandCLI();

        AddLineCommand* addLineCommand = new AddLineCommand(addLineCommandCLI, ad);
        SaveCommand* saveCommand = new SaveCommand(ad, saveCommandCLI, dr);
        SaveAsCommand* saveAsCommand = new SaveAsCommand(ad, saveAsCommandCLI, dr);   
        LoadDocumentCommand* loadDocumentCommand = new LoadDocumentCommand(loadDocumentCommandCLI, dr);
        UnloadDocumentCommand* unloadDocumentCommand = new UnloadDocumentCommand(unloadDocumentCommandCLI, dr);      
        SetActiveDocumentCommand* setActiveDocumentCommnd = new SetActiveDocumentCommand(setActiveDocumentCommandCLI, ad);
        CreateBlockCommand* createBlockCommand = new CreateBlockCommand(createBlockCommandCLI, br, ad);
        RemoveBlockCommand* removeBlockCommand = new RemoveBlockCommand(removeBlockCommandCLI, br, dr);
        SetActiveBlockCommand* setActiveBlockCommand = new SetActiveBlockCommand(setActiveBlockCommandCLI, ab, ad, br);

        // Register the command
        commandRegister->registerCommand(addLineCommand);
        commandRegister->registerCommand(saveCommand);
        commandRegister->registerCommand(saveAsCommand);
        commandRegister->registerCommand(loadDocumentCommand);
        commandRegister->registerCommand(unloadDocumentCommand);
        commandRegister->registerCommand(setActiveDocumentCommnd);
        commandRegister->registerCommand(createBlockCommand);
        commandRegister->registerCommand(removeBlockCommand);
        commandRegister->registerCommand(setActiveBlockCommand);

        cout << "Commands:\n" << commandRegister->showAllCommands() << endl;

        commandRegister->executeCommand(4);

        commandRegister->executeCommand(6);
        
        //commandRegister->executeCommand(7);

        commandRegister->executeCommand(9);

        commandRegister->executeCommand(5);

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
