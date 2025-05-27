#include "../headers/Macro/MacroParser.hpp"

MacroParser* MacroParser::instance = nullptr;

/**
 * @brief Returns the singleton instance of MacroParser.
 * 
 * @return MacroParser* The singleton instance of MacroParser.
 */
MacroParser* MacroParser::getInstance() {
    if (instance == nullptr) {
        instance = new MacroParser();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of MacroParser.
 * 
 * This method deletes the instance of MacroParser and sets it to nullptr.
 */
void MacroParser::destroyInstance() {
    delete instance;
    instance = nullptr;
}

/**
 * @brief Serializes a macro into a string format.
 * 
 * @param macro The macro to serialize.
 * @return string The serialized representation of the macro.
 */
string MacroParser::serialize(Macro* macro) {
    string content = macro->getName() + "|";
    vector<string> commandNames = macro->getCommandNames();
    for (const string& commandName : commandNames) {
        content += commandName + "|";
    }
    content.pop_back();
    content += "\n";
    return content;
}

/**
 * @brief Parses a macro from a string content.
 * 
 * @param content The string content to parse.
 * @return Macro* A pointer to the parsed Macro object.
 * @throws runtime_error if the content is invalid.
 */
Macro* MacroParser::parse(const string& content) {
    vector<string> parts = split(content, '|');
    if (parts.size() < 2) {
        throw std::runtime_error("MacroParser::parseMacro: Invalid macro content");
    }

    string macroName = parts[0];
    vector<string> commandNames(parts.begin() + 1, parts.end());
    
    return new Macro(macroName, commandNames);
}