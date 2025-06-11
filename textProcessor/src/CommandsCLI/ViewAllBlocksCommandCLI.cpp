#include "../../headers/CommandsCLI/ViewAllBlocksCommandCLI.hpp"

void ViewAllBlocksCommandCLI::success() {
}


void ViewAllBlocksCommandCLI::error(string message) {
    cerr << "Error viewing blocks: " << message << endl;
}

void ViewAllBlocksCommandCLI::showBlocksForActiveDoc(string blocksForDocSerialized) {
    cout << "Available blocks for active document:" << endl;
    cout << blocksForDocSerialized << endl;
}

