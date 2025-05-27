#include "../headers/Macro/MacroRegister.hpp"


MacroRegister* MacroRegister::instance = nullptr;
MacroRegister::MacroRegister() {
    this->macroParser = MacroParser::getInstance();
    try {
        this->macros = macroParser->loadMacros();
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroRegister::MacroRegister: " + string(e.what()));
    }
}


MacroRegister::~MacroRegister() {
    for (auto& macro : macros) {
        delete macro;
    }
    macros.clear();
}

/**
 * @brief Returns the singleton instance of MacroRegister.
 * 
 * @return MacroRegister* The singleton instance of MacroRegister.
 */
MacroRegister* MacroRegister::getInstance() {
    if (instance == nullptr) {
        instance = new MacroRegister();
    }
    return instance;
}

/**
 * @brief Destroys the singleton instance of MacroRegister.
 * 
 * This method deletes the instance of MacroRegister and sets it to nullptr.
 */
void MacroRegister::destroyInstance() {
    delete instance;
    instance = nullptr;
}

/**
 * @brief Adds a macro to the register.
 * 
 * @param macroName The name of the macro.
 * @param commandNames The names of the commands in the macro.
 * @throws runtime_error if the macro name is empty.
 */
void MacroRegister::addMacro(string macroName, const vector<string> commandNames) {
    if (macroName.empty()) {
        throw std::runtime_error("MacroRegister::addMacro: Invalid macro name");
    }

    if (findIndex(macroName) != -1) {
        return;
    }

    Macro* newMacro = new Macro(macroName, commandNames);
    macros.push_back(newMacro);

    try {
        macroParser->save(newMacro);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroRegister::addMacro: " + string(e.what()));
    }
}

/**
 * @brief Removes a macro from the register.
 * 
 * @param macroName The name of the macro to remove.
 * @throws runtime_error if the macro name is empty.
 */
void MacroRegister::removeMacro(string macroName) {
    if (macroName.empty()) {
        throw std::runtime_error("MacroRegister::removeMacro: Invalid macro name");
    }

    int index = findIndex(macroName);
    if (index == -1) {
        return;
    }

    Macro* macroToRemove = macros[index];
    macros.erase(macros.begin() + index);
    delete macroToRemove;

    try {
        macroParser->save(macros);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("MacroRegister::removeMacro: " + string(e.what()));
    }
}

/**
 * @brief Retrieves a macro by its name.
 * 
 * @param macroName The name of the macro to retrieve.
 * @return Macro* Pointer to the macro if found, nullptr otherwise.
 * @throws runtime_error if the macro name is empty or not found.
 */
Macro* MacroRegister::getMacro(string& macroName) {
    if (macroName.empty()) {
        throw std::runtime_error("MacroRegister::getMacro: Invalid macro name");
    }

    int index = findIndex(macroName);
    if (index == -1) {
        throw std::runtime_error("MacroRegister::getMacro: Macro not found");
    }

    return macros[index];
}

/**
 * @brief Retrieves all macros in the register.
 * 
 * @return vector<Macro*> A vector of pointers to all macros.
 */
vector<Macro*> MacroRegister::getAllMacros() {
    return macros; 
}

/**
 * @brief Displays all macros in a string format.
 * 
 * @return string A string representation of all macros.
 */
string MacroRegister::showMacros() {
    string result;
    for (Macro* macro : macros) {
        result += macro->getMacroName() + ": ";
        vector<string> commandNames = macro->getCommandNames();
        for (const auto& commandName : commandNames) {
            result += commandName + " ";
        }
        result += "\n";
    }
    return result;
}
