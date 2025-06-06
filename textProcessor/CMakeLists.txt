cmake_minimum_required(VERSION 3.10)
project(textProcessor VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(headers)

file(GLOB_RECURSE SOURCES
    "main.cpp"
    "src/*.cpp"
    "src/*/*.cpp"
    "src/Lines/LineCreator.cpp"
    "src/Document/Document.cpp"
    "src/Document/DocumentManager.cpp"
    "src/Document/DocumentParser.cpp"
    "src/Document/DocumentRegister.cpp"
    "src/Document/ActiveDocument.cpp"
    "src/Block/Block.cpp"
    "src/Block/BlockParser.cpp"
    "src/Block/BlockRegister.cpp"
    "src/FileManager.cpp"
    "src/Macro/Macro.cpp"
    "src/Macro/MacroManager.cpp"
    "src/Macro/MacroParser.cpp"
    "src/Macro/MacroRegister.cpp"
    "src/Formatter/Formatter.cpp"
    "src/Formatter/ActiveFormatter.cpp"
    "src/Formatter/CenterFormatter.cpp"
    "src/Formatter/DirectFormatter.cpp"
    "src/Formatter/WrapFormatter.cpp"
    "src/Commands/Command.cpp"
    "src/Commands/CommandRegister.cpp"
    "src/Commands/AddLineCommand.cpp"
    "src/CommandsCLI/AddLineCommandCLI.cpp"
    "src/Commands/SaveCommand.cpp"
    "src/CommandsCLi/SaveCommandCLI.cpp"
    "src/Commands/SaveAsCommand.cpp"
    "src/CommandsCLi/SaveAsCommandCLI.cpp"
)

add_executable(textProcessor ${SOURCES})
