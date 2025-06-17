/**
 * @file MacroRegister.cpp
 * @author MK
 * @brief A class to register and manage macros in the text processor application.
 */

#include "../headers/Macro/MacroRegister.hpp"


MacroRegister* MacroRegister::instance = nullptr;
MacroRegister::MacroRegister() :DataRegister() {}


MacroRegister::~MacroRegister() {}

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
        throw runtime_error(ERROR_INVALID_ITEM_NAME);
    }

    Macro* newMacro = new Macro(macroName, commandNames);

    try{
        addItem(newMacro);
    } catch (const runtime_error& e) {
        delete newMacro;
        throw runtime_error(string(e.what()));
    } catch (const logic_error& e) {
        delete newMacro;
    }
}

/**
 * @brief Returns the type of the register.
 * 
 * @return string The type of the register.
 */
string MacroRegister::getType()
{
    return "MacroRegister";
}

/**
 * @brief Returns the name of the macro.
 * 
 * @param macro The macro to get the name from.
 * @return string The name of the macro.
 * @throws runtime_error if the macro is null.
 */
string MacroRegister::getItemName(Macro* macro)
{
    if (macro == nullptr) {
        throw runtime_error(ERROR_MACRO_NOT_FOUND);
    }
    return macro->getName();
}


string MacroRegister::toString() const {
    string out;
    for (Macro* macro : items) {
        out += MacroParser::getInstance()->serialize(macro);
    }
    return out;
}