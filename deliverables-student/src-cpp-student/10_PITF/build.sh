#!/usr/bin/env bash

HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"

set -e
set -x

clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -o a.out_raw banking_base_rawptr.cpp
#clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -o a.out_smart banking_base_smartptr.cpp
