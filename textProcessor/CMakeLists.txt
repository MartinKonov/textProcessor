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
    "src/FileManager.cpp"
)

add_executable(textProcessor ${SOURCES})
