#!/usr/bin/env bash
set -e
set -x


HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}

CPP_FLAGS="-std=c++14 -fno-elide-constructors -DTRACE"


clang++ -I${HEADER_PATH}/helpers ${CPP_FLAGS} -c main_byte.cpp
clang++ -I${HEADER_PATH}/helpers ${CPP_FLAGS} -c Byte.cpp

clang++ -o a.out_Byte  main_byte.o Byte.o


