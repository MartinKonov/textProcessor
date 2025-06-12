#include "../headers/TextProcessor.hpp"


TextProcessor* TextProcessor::instance = nullptr;

TextProcessor::TextProcessor() {
    initializeDataClasses();
    initializeCommandCLIs();
    initializeCommands();
    registerCommands();
}

TextProcessor* TextProcessor::getInstance() {
    if (instance == nullptr) {
        instance = new TextProcessor();
    }
    return instance;
}

void TextProcessor::destroyInstance() {
    delete instance;
    instance = nullptr;
}

TextProcessor::~TextProcessor() {

    delete addLineCommandCLI;
    delete saveCommandCLI;
    delete saveAsCommandCLI;
    delete loadDocumentCommandCLI;
    delete unloadDocumentCommandCLI;
    delete setActiveDocumentCommandCLI;
    delete createBlockCommandCLI;
    delete removeBlockCommandCLI;
    delete setActiveBlockCommandCLI;
    delete sortCommandCLI;
    delete viewAllBlocksCommandCLI;
    delete removeActiveBlockCommandCLI;

    delete addLineCommand;
    delete saveCommand;
    delete saveAsCommand;
    delete loadDocumentCommand;
    delete unloadDocumentCommand;
    delete setActiveDocumentCommand;
    delete createBlockCommand;
    delete removeBlockCommand;
    delete setActiveBlockCommand;
    delete sortCommand;
    delete viewAllBlocksCommand;
    delete removeActiveBlockCommand;

    delete commandRegister;
    delete documentRegister;
    delete documentParser;
    delete activeDocument;
    delete activeBlock;

    BlockRegister::destroyInstance();
    LineCreator::destroyInstance();
}

void TextProcessor::initializeDataClasses() {
    commandRegister = new CommandRegister();
    fileManager = FileManager::getInstance();
    lineCreator = LineCreator::getInstance();
    blockRegister = BlockRegister::getInstance();
    documentParser = new DocumentParser(fileManager, lineCreator);
    documentRegister = new DocumentRegister(documentParser);
    activeDocument = new ActiveDocument(documentRegister);
    activeBlock = new ActiveBlock(blockRegister);
}

void TextProcessor::initializeCommandCLIs() {
    addLineCommandCLI = new AddLineCommandCLI();
    saveCommandCLI = new SaveCommandCLI();
    saveAsCommandCLI = new SaveAsCommandCLI();
    loadDocumentCommandCLI = new LoadDocumentCommandCLI();
    unloadDocumentCommandCLI = new UnloadDocumentCommandCLI();
    setActiveDocumentCommandCLI = new SetActiveDocumentCommandCLI();
    createBlockCommandCLI = new CreateBlockCommandCLI();
    removeBlockCommandCLI = new RemoveBlockCommandCLI();
    setActiveBlockCommandCLI = new SetActiveBlockCommandCLI();
    sortCommandCLI = new SortCommandCLI();
    viewAllBlocksCommandCLI = new ViewAllBlocksCommandCLI();
    removeActiveBlockCommandCLI = new RemoveActiveBlockCommandCLI();
}

void TextProcessor::initializeCommands() {
    addLineCommand = new AddLineCommand(addLineCommandCLI, activeDocument);
    saveCommand = new SaveCommand(activeDocument, saveCommandCLI, documentRegister);
    saveAsCommand = new SaveAsCommand(activeDocument, saveAsCommandCLI, documentRegister);
    loadDocumentCommand = new LoadDocumentCommand(loadDocumentCommandCLI, documentRegister);
    unloadDocumentCommand = new UnloadDocumentCommand(unloadDocumentCommandCLI, documentRegister, activeDocument);
    setActiveDocumentCommand = new SetActiveDocumentCommand(setActiveDocumentCommandCLI, activeDocument);
    createBlockCommand = new CreateBlockCommand(createBlockCommandCLI, blockRegister, activeDocument);
    removeBlockCommand = new RemoveBlockCommand(removeBlockCommandCLI, blockRegister, documentRegister);
    setActiveBlockCommand = new SetActiveBlockCommand(setActiveBlockCommandCLI, activeBlock, activeDocument, blockRegister);
    sortCommand = new SortCommand(sortCommandCLI, activeDocument, activeBlock);
    viewAllBlocksCommand = new ViewAllBlocksCommand(viewAllBlocksCommandCLI, activeDocument, blockRegister);
    removeActiveBlockCommand = new RemoveActiveBlockCommand(removeActiveBlockCommandCLI, activeBlock, activeDocument);
}

void TextProcessor::registerCommands() {
    commandRegister->registerCommand(addLineCommand);
    commandRegister->registerCommand(saveAsCommand);
    commandRegister->registerCommand(saveCommand);
    commandRegister->registerCommand(loadDocumentCommand);
    commandRegister->registerCommand(unloadDocumentCommand);
    commandRegister->registerCommand(setActiveDocumentCommand);
    commandRegister->registerCommand(createBlockCommand);
    commandRegister->registerCommand(removeBlockCommand);
    commandRegister->registerCommand(setActiveBlockCommand);
    commandRegister->registerCommand(sortCommand);
    commandRegister->registerCommand(viewAllBlocksCommand);
    commandRegister->registerCommand(removeActiveBlockCommand);
}


void TextProcessor::run() {

    cout << "Welcome to the Text Processor!" << endl;
    cout << "Type 'help' to see available commands." << endl;

    string commandInput;
    while (true) {
        cout << "> ";
        getline(cin, commandInput);

        if (commandInput == "exit") {
            break;
        } else if (commandInput == "help") {
            cout << "Enter the name or the number of the command to be executed." << endl;
            cout << "exit - Exit the application" << endl;
            cout << "undo - Undo the last command" << endl;
            cout << commandRegister->showAllCommands() << endl;
        } else if (commandInput == "undo") {
            try {
                commandRegister->undo();
            } catch (const std::exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        } else {
            int index;
            if(isUnsignedInt(commandInput)) {
                index = stoi(commandInput) - 1;
            }
            else {
                index = commandRegister->findIndex(commandInput);
            }

            try {
                if (index >= 0) {
                    commandRegister->executeCommand(index);
                } else {
                    cout << "Unknown command: " << commandInput << endl;
                }
            } catch (const std::exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }
}


bool TextProcessor::isUnsignedInt(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
