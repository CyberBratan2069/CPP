#!/usr/bin/env bash
#set -x  # let the shell print commands prior to execution
set -u # # make sure $1 has a value (see below, e.g. main.cpp)
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}

# finally, let the compiler driver do the actual work
echo "building $1 with clang++ ..."
set -x
clang++  -Wall -Wextra -Wpedantic -O0 -std=c++17 -I${HEADER_PATH}/helpers "$@"
