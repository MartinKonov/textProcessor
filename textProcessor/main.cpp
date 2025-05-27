#include <iostream>
#include <fstream>
#include <string>
#include "../headers/Formatter/ActiveFormatter.hpp"

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

/**
 * @brief Test the formatter with the given type and format point.
 */
void testFormatter(const string& formatterType, const string& text, int formatPoint) {
    auto* activeFormatter = ActiveFormatter::getInstance();
    try {
        activeFormatter->setFormatter(formatterType);
        string formatted = activeFormatter->getFormattedString(text, formatPoint);

        cout << "Formatter: " << formatterType << endl;
        cout << "Formatted Output:\n" << formatted << endl;
        cout << "---------------------------------------------" << endl;
    } catch (const std::exception& e) {
        cout << "Error using formatter [" << formatterType << "]: " << e.what() << endl;
    }
}

int main() {
    const string filePath = "/home/mkonov/cProjects/UNI/projectOOP/textProcessor/textProcessor/testFiles/example.txt";

    try {
        string content = loadFileContent(filePath);

        // Test DirectFormatter (formatPoint is ignored)
        //testFormatter("DirectFormatter", content, 50);

        // Test WrapFormatter
        //testFormatter("WrapFormatter", content, 20);

        // Test CenterFormatter
        testFormatter("CenterFormatter", content, 60);

    } catch (const std::exception& e) {
        cout << "Fatal error: " << e.what() << endl;
    }

    ActiveFormatter::destroyInstance();
    return 0;
}
