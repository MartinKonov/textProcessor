#include "../../headers/Commands/ViewAllBlocksCommand.hpp"



ViewAllBlocksCommand::ViewAllBlocksCommand(ViewAllBlocksCommandCLI* cli, ActiveDocument* activeDocument, BlockRegister* blockRegister) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->blockRegister = blockRegister;
}

string ViewAllBlocksCommand::getName() const {
    return "View All Blocks for Active Document";
}

void ViewAllBlocksCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        cli->error("Please set an active document before viewing blocks.");
        return;
    }

    string blocksForDocSerialized = blockRegister->showAllForDocument(activeDocument->getActiveDocument()->getDocName());
    if (blocksForDocSerialized.empty()) {
        cli->error("No blocks found for the active document.");
        return;
    }

    cli->success();
    cli->showBlocksForActiveDoc(blocksForDocSerialized);
}

void ViewAllBlocksCommand::undo() {
}