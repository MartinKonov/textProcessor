/**
 * @file MacroParser.hpp
 * @author MK
 * @brief A class to parse and serialize macros in the text processor application.
 */
#pragma once

#include "Macro.hpp"
#include "../../dataFiles/DataFiles.hpp"
#include "../GenericDataClasses/DataParser.hpp"

/**
 * @brief A class to parse and serialize macros in the text processor application.
 */
class MacroParser : public DataParser<MacroParser, Macro> {
    public:
        static MacroParser* getInstance();
        static void destroyInstance();
    
        string serialize(Macro* macro);
        Macro* parse(const string& content);
        
        static constexpr const char* DATA_FILE = MACRO_DATA_FILE;

        private:
        MacroParser() = default;
        ~MacroParser() = default;
        MacroParser(const MacroParser&) = delete;
        MacroParser& operator=(const MacroParser&) = delete;
        
        static MacroParser* instance;
};