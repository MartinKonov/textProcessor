#include "headers/TextProcessor.hpp"

int main() {
    TextProcessor* textProcessor = TextProcessor::getInstance();
    textProcessor->run();
    cout << "E" << endl;
    TextProcessor::destroyInstance();
    return 0;
}
