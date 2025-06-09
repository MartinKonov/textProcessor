#include "../../headers/CommandsCLI/RemoveBlockCommandCLI.hpp"

void RemoveBlockCommandCLI::success() {
    cout << "Block removed successfully" << endl;
}

void RemoveBlockCommandCLI::error(string message) {
    cerr << "Error removing block: " << message << endl;
}

string RemoveBlockCommandCLI::getBlockName() {
    string blockName;
    cout << "Enter the name of the block to be removed:" << endl;
    getline(cin, blockName);
    return blockName;
}

void RemoveBlockCommandCLI::blockDoesntExist() {
    cerr << "A block with this name doesn't exist." << endl;
}

void RemoveBlockCommandCLI::removedBlockError() {
    cerr << "Can't undo, no previous state of block found" << endl;
}

void RemoveBlockCommandCLI::errorUndo(string message) {
    cerr << "Error durring undo remove block: " << message << endl;
}