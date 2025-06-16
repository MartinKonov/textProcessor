/**
 * @file Command.hpp
 * @author MK
 * @brief An abstract base class for commands in the text processor application.
 * @version 0.1
 * @date 2025-05-26
 */
#pragma once
#include "../../dataFiles/CommandNames.hpp"
#include "../../dataFiles/CommonErrors.hpp"
#include <string>
#include <vector>
#include <stdexcept> 

using std::string;
using std::vector;
using std::runtime_error;

/**
 * @brief An abstract base class for commands in the text processor application.
 * 
 * This class defines the interface for all commands, including methods for execution, undoing, and retrieving the command name.
 */
class Command 
{
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual string getName() const = 0;
        virtual bool isUndoable() const {
            return true;
        }
};