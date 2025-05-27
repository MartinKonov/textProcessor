#include "../headers/Macro/MacroParser.hpp"

MacroParser* MacroParser::instance = nullptr;

MacroParser::MacroParser() {
    this->fileManager = FileManager::getInstance();
}
MacroParser::~MacroParser() {
    // No dynamic memory to free, as FileManager is a singleton
}

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
 * @brief Saves a macro to the file system.
 * 
 * @param macro The macro to save.
 * @throws runtime_error if the file cannot be saved.
 */
void MacroParser::save(Macro* macro) {

    string content = serializeMacro(macro);
    
    try {
        fileManager->loadFile(MACRO_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroParser::save: " + string(e.what()));
    }

    string existingContent = fileManager->getContents(MACRO_DATA_FILE);
    string newContent = existingContent + content;

    try{
        fileManager->setContent(MACRO_DATA_FILE, newContent);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroParser::save: " + string(e.what()));
    }
}

void MacroParser::save(vector<Macro*> macros) {
    string content;
    for (const auto& macro : macros) {
        content += serializeMacro(macro);
    }

    try {
        setNewContent(content);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroParser::save: " + string(e.what()));
    }
}

void MacroParser::setNewContent(string content) {
    try {
        fileManager->loadFile(MACRO_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroParser::setNewContent: " + string(e.what()));
    }

    fileManager->setContent(MACRO_DATA_FILE, content);
    try {
        fileManager->save(MACRO_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroParser::setNewContent: " + string(e.what()));
    }
}


/**
 * @brief Loads all macros from the macro data file.
 * 
 * @return vector<Macro*> A vector of pointers to Macro objects.
 */
vector<Macro*> MacroParser::loadMacros() {
    vector<Macro*> macros;
    try {
        fileManager->loadFile(MACRO_DATA_FILE);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroParser::loadMacros: " + string(e.what()));
    }

    string content = fileManager->getContents(MACRO_DATA_FILE);
    vector<string> lines = split(content, '\n');

    for (const string& line : lines) {
        try {
            Macro* macro = parseMacro(line);
            macros.push_back(macro);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("MacroParser::loadMacros: " + string(e.what()));
        }
    }
    return macros;
}

/**
 * @brief Serializes a macro into a string format.
 * 
 * @param macro The macro to serialize.
 * @return string The serialized representation of the macro.
 */
string MacroParser::serializeMacro(Macro* macro) {
    string content = macro->getMacroName() + "|";
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
Macro* MacroParser::parseMacro(const string& content) {
    vector<string> parts = split(content, '|');
    if (parts.size() < 2) {
        throw std::runtime_error("MacroParser::parseMacro: Invalid macro content");
    }

    string macroName = parts[0];
    vector<string> commandNames(parts.begin() + 1, parts.end());
    
    return new Macro(macroName, commandNames);
}