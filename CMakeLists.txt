cmake_minimum_required(VERSION 3.14)
project(Compilador)

find_package(FLEX)
find_package(BISON)

FLEX_TARGET(CompiLexer CompiLexerImpl.l
            ${CMAKE_CURRENT_BINARY_DIR}/CompiLexerImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/CompiLexerImpl.h
            )

BISON_TARGET(CompiParser CompiParserImpl.y
            ${CMAKE_CURRENT_BINARY_DIR}/CompiParserImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/CompiParserImpl.h
            )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    ${FLEX_CompiLexer_OUTPUTS}
    ${BISON_CompiParser_OUTPUTS}
    CompiParser.hpp
    CompiParser.cpp
    CompiLexer.hpp
    CompiLexer.cpp
    main.cpp
 )