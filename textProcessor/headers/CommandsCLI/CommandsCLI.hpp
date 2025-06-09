/**
 * @file CommandsCLI.hpp
 * @author MK
 * @brief An abstract base class for commands in the text processor application that interact with the command line interface.
 * @version 0.1
 * @date 2025-05-29
 */
#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::exception;

class CommandsCLI {
    public:
    virtual ~CommandsCLI() = default;
    virtual void success() = 0;
    virtual void error(string message = "") = 0;
};