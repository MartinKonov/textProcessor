#include <iostream>
#include <fstream>
#include <string>
#include "../headers/Commands/CommandRegister.hpp"
#include "../headers/Commands/AddLineCommand.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


string loadFileContent(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filePath);
    }

    string content, line;
    while (getline(file, line)) {
        content += line + '\n';
    }

    return content;
}

int main() {
    const string filePath = "/home/mkonov/cProjects/UNI/projectOOP/textProcessor/textProcessor/testFiles/example.txt";

    try {
        string fileContent = loadFileContent(filePath);
        cout << "File content loaded successfully:\n" << fileContent << endl;

        // Initialize CommandRegister and AddLineCommand
        CommandRegister* commandRegister = CommandRegister::getInstance();
        AddLineCommandCLI* addLineCommandCLI = new AddLineCommandCLI();
        AddLineCommand* addLineCommand = new AddLineCommand(addLineCommandCLI);

        // Register the command
        commandRegister->registerCommand(addLineCommand);

        commandRegister->showAllCommands();
        // Execute the command
        //commandRegister->executeCommand(); // Assuming this is the index of the AddLineCommand

    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
