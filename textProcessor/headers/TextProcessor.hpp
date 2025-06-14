/**
 * @file TextProcessor.hpp
 * @author MK
 * @brief The main class for the text processor application, responsible for managing commands, documents, and blocks.
 */
#pragma once
#include "Commands/CommandRegister.hpp"
#include "Commands/AddLineCommand.hpp"
#include "Commands/SaveCommand.hpp"
#include "CommandsCLI/SaveCommandCLI.hpp"
#include "Commands/SaveAsCommand.hpp"
#include "CommandsCLI/SaveAsCommandCLI.hpp"
#include "Commands/LoadDocumentCommand.hpp"
#include "CommandsCLI/LoadDocumentCommandCLI.hpp"
#include "Commands/UnloadDocumentCommand.hpp"
#include "CommandsCLI/UnloadDocumentCommandCLI.hpp"
#include "Commands/SetActiveDocumentCommand.hpp"
#include "CommandsCLI/SetActiveDocumentCommandCLI.hpp"
#include "Commands/CreateBlockCommand.hpp"
#include "CommandsCLI/CreateBlockCommandCLI.hpp"
#include "Commands/RemoveBlockCommand.hpp"
#include "CommandsCLI/RemoveBlockCommandCLI.hpp"
#include "Commands/SetActiveBlockCommand.hpp"
#include "CommandsCLI/SetActiveBlockCommandCLI.hpp"
#include "Block/ActiveBlock.hpp"
#include "Commands/SortCommand.hpp"
#include "CommandsCLI/SortCommandCLI.hpp"
#include "Commands/ViewAllBlocksCommand.hpp"
#include "CommandsCLI/ViewAllBlocksCommandCLI.hpp"
#include "Commands/RemoveActiveBlockCommand.hpp"
#include "CommandsCLI/RemoveActiveBlockCommandCLI.hpp"
#include "Commands/ListLoadedDocumentsCommand.hpp"
#include "CommandsCLI/ListLoadedDocumentsCommandCLI.hpp"
#include "Commands/SetFormatCommand.hpp"
#include "CommandsCLI/SetFormatCommandCLI.hpp"
#include "Commands/ViewDocumentCommand.hpp"
#include "CommandsCLI/ViewAllBlocksCommandCLI.hpp"
#include "Commands/RemoveLineCommand.hpp"
#include "CommandsCLI/RemoveLineCommandCLI.hpp"
#include "Commands/InsertLineCommand.hpp"
#include "CommandsCLI/InsertLineCommandCLI.hpp"
#include "Commands/ChangeLineCommand.hpp"
#include "CommandsCLI/ChangeLineCommandCLI.hpp"
#include "Commands/ToUpperCommand.hpp"
#include "CommandsCLI/ToUpperCommandCLI.hpp"
#include "Commands/ToLowerCommand.hpp"
#include "CommandsCLI/ToLowerCommandCLI.hpp"
#include "Commands/TrimTrailingCommand.hpp"
#include "CommandsCLI/TrimTrailingCommandCLI.hpp"
#include "Commands/TrimLeadingCommand.hpp"
#include "CommandsCLI/TrimLeadingCommandCLI.hpp"
#include "Commands/ScrambleCommand.hpp"
#include "CommandsCLI/ScrambleCommandCLI.hpp"
#include "Commands/RemoveRepeatsCommand.hpp"
#include "CommandsCLI/RemoveRepeatsCommandCLI.hpp"
#include "Commands/ShowDocumentNameCommand.hpp"
#include "CommandsCLI/ShowDocumentNameCommandCLI.hpp"
#include "Commands/ShowDocumentNumLinesCommand.hpp"
#include "CommandsCLI/ShowDocumentNumLinesCommandCLI.hpp"

/**
 * @brief The main class for the text processor application, responsible for managing commands, documents, and blocks.
 */
class TextProcessor {
    public:
        static TextProcessor* getInstance();
        static void destroyInstance();

        void run();

    private:

        TextProcessor();
        ~TextProcessor();
        TextProcessor(const TextProcessor&) = delete;
        TextProcessor& operator=(const TextProcessor&) = delete;

        static TextProcessor* instance;

        void initializeCommands();
        void initializeCommandCLIs();
        void initializeDataClasses();
        void registerCommands();
        bool isUnsignedInt(const string& str);

        // Data classes
        CommandRegister* commandRegister;
        FileManager* fileManager;
        LineCreator* lineCreator;
        DocumentParser* documentParser;
        DocumentRegister* documentRegister;
        BlockRegister* blockRegister;
        ActiveDocument* activeDocument;
        ActiveBlock* activeBlock;
        ActiveFormatter* activeFormatter;

        // Command CLIs
        AddLineCommandCLI* addLineCommandCLI ;
        SaveCommandCLI* saveCommandCLI;
        SaveAsCommandCLI* saveAsCommandCLI;
        LoadDocumentCommandCLI* loadDocumentCommandCLI;
        UnloadDocumentCommandCLI* unloadDocumentCommandCLI;
        SetActiveDocumentCommandCLI* setActiveDocumentCommandCLI;
        CreateBlockCommandCLI* createBlockCommandCLI;
        RemoveBlockCommandCLI* removeBlockCommandCLI;
        SetActiveBlockCommandCLI* setActiveBlockCommandCLI;
        SortCommandCLI* sortCommandCLI;
        ViewAllBlocksCommandCLI* viewAllBlocksCommandCLI;
        RemoveActiveBlockCommandCLI* removeActiveBlockCommandCLI;
        ListLoadedDocumentsCommandCLI* listLoadedDocumentsCommandCLI;
        SetFormatCommandCLI* setFormatCommandCLI;
        ViewDocumentCommandCLI* viewDocumentCommandCLI;
        RemoveLineCommandCLI* removeLineCommandCLI;
        InsertLineCommandCLI* insertLineCommandCLI;
        ChangeLineCommandCLI* changeLineCommandCLI;
        ToUpperCommandCLI* toUpperCommandCLI;
        ToLowerCommandCLI* toLowerCommandCLI;
        TrimTrailingCommandCLI* trimTrailingCommandCLI;
        TrimLeadingCommandCLI* trimLeadingCommandCLI;
        ScrambleCommandCLI* scrambleCommandCLI;
        RemoveRepeatsCommandCLI* removeRepeatsCommandCLI;
        ShowDocumentNameCommandCLI* showDocumentNameCommandCLI;
        ShowDocumentNumLinesCommandCLI* showDocumentNumLinesCommandCLI;

        // Commands
        AddLineCommand* addLineCommand;
        SaveCommand* saveCommand;
        SaveAsCommand* saveAsCommand;
        LoadDocumentCommand* loadDocumentCommand;
        UnloadDocumentCommand* unloadDocumentCommand;
        SetActiveDocumentCommand* setActiveDocumentCommand;
        CreateBlockCommand* createBlockCommand;
        RemoveBlockCommand* removeBlockCommand;
        SetActiveBlockCommand* setActiveBlockCommand;
        SortCommand* sortCommand;
        ViewAllBlocksCommand* viewAllBlocksCommand;
        RemoveActiveBlockCommand* removeActiveBlockCommand;
        ListLoadedDocumentsCommand* listLoadedDocumentsCommand;
        SetFormatCommand* setFormatCommand;
        ViewDocumentCommand* viewDocumentCommand;
        RemoveLineCommand* removeLineCommand;
        InsertLineCommand* insertLineCommand;
        ChangeLineCommand* changeLineCommand;
        ToUpperCommand* toUpperCommand;
        ToLowerCommand* toLowerCommand;
        TrimTrailingCommand* trimTrailingCommand;
        TrimLeadingCommand* trimLeadingCommand;
        ScrambleCommand* scrambleCommand;
        RemoveRepeatsCommand* removeRepeatsCommand;
        ShowDocumentNameCommand* showDocumentNameCommand;
        ShowDocumentNumLinesCommand* showDocumentNumLinesCommand;
};
