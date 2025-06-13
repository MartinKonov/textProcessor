#include "headers/TextProcessor.hpp"

int main() {
    TextProcessor* textProcessor = TextProcessor::getInstance();
    textProcessor->run();
    TextProcessor::destroyInstance();
    return 0;
}
