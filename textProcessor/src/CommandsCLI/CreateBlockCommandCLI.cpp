#include "../../headers/CommandsCLI/CreateBlockCommandCLI.hpp"

void CreateBlockCommandCLI::success(){
    cout << "Block created successfully" << endl;
}

void CreateBlockCommandCLI::errorNoActiveDocument() {
    cerr << "No active document set, cannot create block with no active document" << endl;
}

string CreateBlockCommandCLI::getBlockName() {
    string blockName;
    cout << "Enter block name:" << endl;
    getline(cin, blockName);
    return blockName;
}

void CreateBlockCommandCLI::blockExists() {
    cout << "A block with this name already exists. Try again" << endl;
}

size_t CreateBlockCommandCLI::getStartLineIndex() {
    string input;
    size_t startLineIndex = 0;

    cout << "Enter the block's start line index:" << endl;
    getline(cin, input);

    try {
        startLineIndex = stoul(input);
    } catch (const exception& e) {
        cerr << "Invalid number entered. Try again." << endl;
    }

    return startLineIndex;
}

size_t CreateBlockCommandCLI::getEndLineIndex() {
    string input;
    size_t endLineIndex = 0;

    cout << "Enter the block's end line index:" << endl;
    getline(cin, input);

    try {
        endLineIndex = stoul(input);
    } catch (const exception& e) {
        cerr << "Invalid number entered. Try again." << endl;
    }

    return endLineIndex;
}

void CreateBlockCommandCLI::error(string message) {
    cerr << "CreateBlockCommand error while undo: " << message << endl;
}

void CreateBlockCommandCLI::successUndo() {
    cout << "Create block undo successful" << endl;
}