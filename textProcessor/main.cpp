#include "headers/TextProcessor.hpp"

int main() {
    TextProcessor* textProcessor = TextProcessor::getInstance();
    textProcessor->run();
    textProcessor->destroyInstance();
    return 0;
}
