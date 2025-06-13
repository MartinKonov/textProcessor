#include "../../headers/CommandsCLI/ListLoadedDocumentsCommandCLI.hpp"


void ListLoadedDocumentsCommandCLI::success() {

}

void ListLoadedDocumentsCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

void ListLoadedDocumentsCommandCLI::listDocuments(string documentList) {
    if (documentList.empty()) {
        cout << "No documents loaded." << endl;
    } else {
        cout << documentList << endl;
    }
}