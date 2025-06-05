#pragma once

#include "CommandsCLI.hpp"


class SaveCommandCLI : public CommandsCLI {

    public:
        SaveCommandCLI() = default;
        ~SaveCommandCLI() override = default;

        void success() override;
        void documentHasntChanged();
        void errorSaving(string err);
};