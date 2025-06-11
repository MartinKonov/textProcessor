#include "../../headers/CommandsCLI/RemoveActiveBlockCommandCLI.hpp"


void RemoveActiveBlockCommandCLI::success() {
    cout << "Active block removed successfully." << endl;
}

void RemoveActiveBlockCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

void RemoveActiveBlockCommandCLI::nothingToUndo() {
    cout << "Nothing to undo." << endl;
}

void RemoveActiveBlockCommandCLI::documentHasChanged() {
    cerr << "The document has changed since last operation. Cannot undo." << endl;
}

void RemoveActiveBlockCommandCLI::errorUndo(string message) {
    cerr << "Error while undo: " << message << endl;
}