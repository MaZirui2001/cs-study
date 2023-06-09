# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)
project(demo)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 11)

# add antrl4cpp artifacts to project environment
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../antlr4-runtime)
# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
#set(ANTLR_EXECUTABLE full/path/to/antlr-4.7.2-complete.jar)

# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer to build dependencies.
antlr_target(SampleGrammarLexer ${CMAKE_CURRENT_SOURCE_DIR}/grammar/labLexer.g4 LEXER
             PACKAGE antlr4)

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

# add generated grammar to demo binary target
add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
               ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS})
target_link_libraries(demo ${CMAKE_CURRENT_SOURCE_DIR}/lib/libantlr4-runtime.so.4.8)
