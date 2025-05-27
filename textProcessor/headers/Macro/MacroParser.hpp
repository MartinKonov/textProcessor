#pragma once

#include "Macro.hpp"
#include "../DataFiles.hpp"
#include "../GenericDataClasses/DataParser.hpp"

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