/**
 * @file Command.hpp
 * @author MK
 * @brief An abstract base class for commands in the text processor application.
 * @version 0.1
 * @date 2025-05-26
 */
#pragma once
#include <string>
#include <vector>
#include <stdexcept> 

using std::string;
using std::vector;

class Command 
{
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual string getName() const = 0;
};