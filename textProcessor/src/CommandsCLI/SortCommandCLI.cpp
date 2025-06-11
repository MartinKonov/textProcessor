#include "../../headers/CommandsCLI/SortCommandCLI.hpp"


void SortCommandCLI::success() {
    cout << "Document sorted successfully." << endl;
}

void SortCommandCLI::error(string message) {
    cerr << message << endl;
}

void SortCommandCLI::nothingToUndo() {
    cout << "Nothing has changed, nothing to undo." << endl;
}

void SortCommandCLI::successUndo() {
    cout << "Sort operation undone successfully." << endl;
}