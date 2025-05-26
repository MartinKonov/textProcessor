#pragma once

/**
 * @file Command.hpp
 * @author MK
 * @brief An abstract base class for commands in the text processor application.
 * @version 0.1
 * @date 2025-05-26
 */
class Command 
{
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual const char* getName() const = 0;
};