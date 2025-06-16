/**
 * @file TextProcessor.cpp
 * @author MK
 * @brief The main class for the text processor application, responsible for managing commands, documents, and blocks.
 */
#include "../headers/TextProcessor.hpp"


TextProcessor* TextProcessor::instance = nullptr;

/**
 * @brief Constructor for the TextProcessor class.
 * Initializes data classes, command CLIs, commands, and registers them.
 */
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

/**
 * @brief Destructor for the TextProcessor class.
 */
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
    delete setFormatCommandCLI;
    delete viewDocumentCommandCLI;
    delete removeLineCommandCLI;
    delete listLoadedDocumentsCommandCLI;
    delete insertLineCommandCLI;
    delete changeLineCommandCLI;
    delete toUpperCommandCLI;
    delete toLowerCommandCLI;
    delete trimTrailingCommandCLI;
    delete trimLeadingCommandCLI;
    delete scrambleCommandCLI;
    delete removeRepeatsCommandCLI;
    delete showDocumentNameCommandCLI;
    delete showDocumentNumLinesCommandCLI;
    delete showDocumentNumSymbolsCommandCLI;
    delete showDocumentHasChangedCommandCLI;
    delete addMacroCommandCLI;
    delete removeMacroCommandCLI;
    delete viewAllMacrosCommandCLI;

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
    delete setFormatCommand;
    delete viewDocumentCommand;
    delete listLoadedDocumentsCommand;
    delete removeLineCommand;
    delete insertLineCommand;
    delete changeLineCommand;
    delete toUpperCommand;
    delete toLowerCommand;
    delete trimTrailingCommand;
    delete trimLeadingCommand;
    delete scrambleCommand;
    delete removeRepeatsCommand;
    delete showDocumentNameCommand;
    delete showDocumentNumLinesCommand;
    delete showDocumentNumSymbolsCommand;
    delete showDocumentHasChangedCommand;
    delete addMacroCommand;
    delete removeMacroCommand;
    delete viewAllMacrosCommand;

    delete commandRegister;
    delete documentRegister;
    delete documentParser;
    delete activeDocument;
    delete activeBlock;

    MacroRegister::destroyInstance();
    BlockRegister::destroyInstance();
    LineCreator::destroyInstance();
    FileManager::destroyInstance();
}

/**
 * @brief Initializes the data classes used in the text processor.
 * Creates instances of CommandRegister, FileManager, LineCreator, DocumentParser, DocumentRegister, ActiveDocument, and ActiveBlock.
 */
void TextProcessor::initializeDataClasses() {
    macroRegister = MacroRegister::getInstance();
    commandRegister = new CommandRegister(macroRegister);
    fileManager = FileManager::getInstance();
    lineCreator = LineCreator::getInstance();
    blockRegister = BlockRegister::getInstance();
    documentParser = new DocumentParser(fileManager, lineCreator);
    documentRegister = new DocumentRegister(documentParser);
    activeDocument = new ActiveDocument(documentRegister);
    activeBlock = new ActiveBlock(blockRegister);
    activeFormatter = new ActiveFormatter();
}

/**
 * @brief Initializes the command CLIs used in the text processor.
 * Creates instances of various command CLI classes.
 */
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
    listLoadedDocumentsCommandCLI = new ListLoadedDocumentsCommandCLI();
    setFormatCommandCLI = new SetFormatCommandCLI();
    viewDocumentCommandCLI = new ViewDocumentCommandCLI();
    removeLineCommandCLI = new RemoveLineCommandCLI();
    insertLineCommandCLI = new InsertLineCommandCLI();
    changeLineCommandCLI = new ChangeLineCommandCLI();
    toUpperCommandCLI = new ToUpperCommandCLI();
    toLowerCommandCLI = new ToLowerCommandCLI();
    trimTrailingCommandCLI = new TrimTrailingCommandCLI();
    trimLeadingCommandCLI = new TrimLeadingCommandCLI();
    scrambleCommandCLI = new ScrambleCommandCLI();
    removeRepeatsCommandCLI = new RemoveRepeatsCommandCLI();
    showDocumentNameCommandCLI = new ShowDocumentNameCommandCLI();
    showDocumentNumLinesCommandCLI = new ShowDocumentNumLinesCommandCLI();
    showDocumentNumSymbolsCommandCLI = new ShowDocumentNumSymbolsCommandCLI();
    showDocumentHasChangedCommandCLI = new ShowDocumentHasChangedCommandCLI();
    addMacroCommandCLI = new AddMacroCommandCLI();
    removeMacroCommandCLI = new RemoveMacroCommandCLI();
    viewAllMacrosCommandCLI = new ViewAllMacrosCommandCLI();
}

/**
 * @brief Initializes the commands used in the text processor.
 * Creates instances of various command classes and associates them with their respective CLIs and data classes.
 */
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
    listLoadedDocumentsCommand = new ListLoadedDocumentsCommand(listLoadedDocumentsCommandCLI, documentRegister);
    setFormatCommand = new SetFormatCommand(setFormatCommandCLI, activeFormatter);
    viewDocumentCommand = new ViewDocumentCommand(viewDocumentCommandCLI, activeFormatter, activeDocument, documentRegister);
    removeLineCommand = new RemoveLineCommand(removeLineCommandCLI, activeDocument);
    insertLineCommand = new InsertLineCommand(insertLineCommandCLI, activeDocument);
    changeLineCommand = new ChangeLineCommand(changeLineCommandCLI, activeDocument);
    toUpperCommand = new ToUpperCommand(toUpperCommandCLI, activeDocument, activeBlock);
    toLowerCommand = new ToLowerCommand(toLowerCommandCLI, activeDocument, activeBlock);
    trimTrailingCommand = new TrimTrailingCommand(trimTrailingCommandCLI, activeDocument, activeBlock);
    trimLeadingCommand = new TrimLeadingCommand(trimLeadingCommandCLI, activeDocument, activeBlock);
    scrambleCommand = new ScrambleCommand(scrambleCommandCLI, activeDocument, activeBlock);
    removeRepeatsCommand = new RemoveRepeatsCommand(removeRepeatsCommandCLI, activeDocument, activeBlock);
    showDocumentNameCommand = new ShowDocumentNameCommand(showDocumentNameCommandCLI, activeDocument);
    showDocumentNumLinesCommand = new ShowDocumentNumLinesCommand(showDocumentNumLinesCommandCLI, activeDocument);
    showDocumentNumSymbolsCommand = new ShowDocumentNumSymbolsCommand(showDocumentNumSymbolsCommandCLI, activeDocument);
    showDocumentHasChangedCommand = new ShowDocumentHasChangedCommand(showDocumentHasChangedCommandCLI, activeDocument);
    addMacroCommand = new AddMacroCommand(addMacroCommandCLI, macroRegister);
    removeMacroCommand = new RemoveMacroCommand(removeMacroCommandCLI, macroRegister);
    viewAllMacrosCommand = new ViewAllMacrosCommand(viewAllMacrosCommandCLI, macroRegister);
}

/**
 * @brief Registers all commands with the command register.
 * This method adds all the created command instances to the command register for execution.
 */
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
    commandRegister->registerCommand(listLoadedDocumentsCommand); 
    commandRegister->registerCommand(setFormatCommand);
    commandRegister->registerCommand(viewDocumentCommand);
    commandRegister->registerCommand(removeLineCommand);
    commandRegister->registerCommand(insertLineCommand);
    commandRegister->registerCommand(changeLineCommand);
    commandRegister->registerCommand(toUpperCommand);
    commandRegister->registerCommand(toLowerCommand);
    commandRegister->registerCommand(trimTrailingCommand);
    commandRegister->registerCommand(trimLeadingCommand);
    commandRegister->registerCommand(scrambleCommand);
    commandRegister->registerCommand(removeRepeatsCommand);
    commandRegister->registerCommand(showDocumentNameCommand);
    commandRegister->registerCommand(showDocumentNumLinesCommand);
    commandRegister->registerCommand(showDocumentNumSymbolsCommand);
    commandRegister->registerCommand(showDocumentHasChangedCommand);
    commandRegister->registerCommand(addMacroCommand);
    commandRegister->registerCommand(removeMacroCommand);
    commandRegister->registerCommand(viewAllMacrosCommand);
}

/**
 * @brief Runs the text processor application.
 * This method starts the command loop, allowing users to enter commands and execute them.
 * It also handles special commands like 'exit', 'help', and 'undo'.
 */
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

/**
 * @brief Checks if a string represents an unsigned integer.
 * 
 * @param str The string to check.
 * @return true if the string is an unsigned integer, false otherwise.
 */
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
