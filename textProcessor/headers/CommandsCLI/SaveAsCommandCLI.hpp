#pragma once

#include "CommandsCLI.hpp"


class SaveAsCommandCLI : public CommandsCLI {

    public:
        SaveAsCommandCLI() = default;
        ~SaveAsCommandCLI() override = default;

        void success() override;
        void documentHasntChanged();
        void errorSaving(string err);
        string getNewDocName();
};