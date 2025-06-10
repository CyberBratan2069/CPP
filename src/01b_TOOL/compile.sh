#!/usr/bin/env bash
echo -e "\033[01;34m============== building ... ==============\033[0m"
set -e
set -x

# shellcheck disable=SC2034
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
# shellcheck disable=SC2034
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17 -Wno-unused-variable"

clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ main.cpp polynom1.cpp polynom2.cpp -o main




