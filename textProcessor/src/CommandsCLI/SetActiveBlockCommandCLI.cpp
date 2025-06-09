#include "../../headers/CommandsCLI/SetActiveBlockCommandCLI.hpp"


void SetActiveBlockCommandCLI::success() {
    cout << "Active block set successfully" << endl;
}

void SetActiveBlockCommandCLI::error(string message) {
    cerr << "Error setting new active block: " << message << endl;
}

void SetActiveBlockCommandCLI::errorActiveDocument(){
    cerr << "Please set active document before trying to set active block" << endl;
}

void SetActiveBlockCommandCLI::showBlocksForActiveDoc(string blocksForDocSerialized) {
    cout << "Available blocks for current document:" << endl;
    cout << blocksForDocSerialized << endl;
}

string SetActiveBlockCommandCLI::getNewActiveBlockName() {
    cout << "Enter the name of the desired new active block:" << endl;
    string blockName;
    getline(cin, blockName);
    return blockName;
}

void SetActiveBlockCommandCLI::nothingToUndo() {
    cout << "Nothing has changed, nothing to undo." << endl;
}

void SetActiveBlockCommandCLI::documentHasChanged() {
    cout << "Active document has changed since last active block. Try to set a new active "
     << "block with the blocks available for the current active document." << endl;
}

void SetActiveBlockCommandCLI::errorUndo(string message) {
    cout << "Error undo of set active block command: " << message << endl;
}