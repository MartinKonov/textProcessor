#pragma once
#include "CommandsCLI.hpp"



class RemoveActiveBlockCommandCLI : public CommandsCLI {
 public:
    RemoveActiveBlockCommandCLI() = default;
    ~RemoveActiveBlockCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    void nothingToUndo();
    void documentHasChanged();
    void errorUndo(string message);
};