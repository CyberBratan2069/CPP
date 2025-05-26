#!/bin/bash

set -eux

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../../90_aux_src}

clang++ -o/dev/null ${CPPFLAGS} -I${HEADER_PATH}/helpers -c logger.hpp # syntax check

clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -c logger.cpp
clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -c main.cpp
clang++ -o a.out main.o logger.o
