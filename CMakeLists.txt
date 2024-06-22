cmake_minimum_required(VERSION 2.6)
project(lpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FLEX)
find_package(BISON)


find_program (TREECC treecc
              PATHS /usr /usr/local /opt /opt/local $ENV{TREECC_DIR}
              PATH_SUFFIXES treecc/bin bin )

if (TREECC)
    message(STATUS "Using treecc executable ${TREECC}")
else(TREECC)
    message(FATAL_ERROR "treecc was not found. Try setting TREECC_DIR environment variable")
endif(TREECC)


add_custom_command (
  OUTPUT CompiAst.cpp CompiAst.hpp
  COMMAND ${TREECC} -o CompiAst.cpp -h CompiAst.hpp ${PROJECT_SOURCE_DIR}/CompiAst.tc
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/CompiAst.tc
  )


FLEX_TARGET(CompiLexer CompiLexerImpl.l
            ${CMAKE_CURRENT_BINARY_DIR}/CompiLexerImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/CompiLexerImpl.hpp
            )

BISON_TARGET(CompiParser CompiParserImpl.y
            ${CMAKE_CURRENT_BINARY_DIR}/CompiParserImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/CompiParserImpl.hpp
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
    CompiAst.hpp
    CompiAst.cpp
    main.cpp
 )