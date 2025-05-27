#pragma once

#include "Macro.hpp"
#include "../FileManager.hpp"
#include "../DataFiles.hpp"

class MacroParser {
    public:
        static MacroParser* getInstance();
        static void destroyInstance();
    
        void save(Macro* macro);
        vector<Macro*> loadMacros();
        void save(vector<Macro*> macros);
        string serializeMacro(Macro* macro);
        Macro* parseMacro(const string& content);

    private:
        MacroParser();
        ~MacroParser();
    
        static MacroParser* instance;
        FileManager* fileManager;
        vector<string> split(const string& str, char delimiter);
        vector<Macro*> parseMacros(const string& content);
        void setNewContent(string content);
};