/**
 * @file SortCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the SortCommand.
 */

#pragma once
#include "CommandsCLI.hpp"



class SortCommandCLI : public CommandsCLI {

    public:
    SortCommandCLI() = default;
    ~SortCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;

    void nothingToUndo();
    void successUndo();
};