#!/usr/bin/env bash
############################################
##          E N V I R O N M E N T         ##
############################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
set -e                     # exit on first error
set -x

############################################
##            C O M P I L E R             ##
############################################

CPPFLAGS="-Wall -Wextra -Wpedantic -Ofast -std=c++17"

clang++ -o a.out_max3 $CPPFLAGS -I${HEADER_PATH}/helpers z_max3.cpp


clang++ $CPPFLAGS -I${HEADER_PATH}/helpers -c z_int2str_main.cpp
clang++ $CPPFLAGS -I${HEADER_PATH}/helpers -c z_int2str_helpers.cpp
clang++ -o a.out_int2str  z_int2str_main.o z_int2str_helpers.o
./a.out_int2str 16
time ./a.out_int2str 100000000 >/dev/null


clang++ -DTEMPLATED $CPPFLAGS -I${HEADER_PATH}/helpers -c z_int2str_main.cpp
clang++ -DTEMPLATED $CPPFLAGS -I${HEADER_PATH}/helpers -c z_int2str_helpers.cpp
clang++ -o a.out_int2str_T  z_int2str_main.o z_int2str_helpers.o
./a.out_int2str_T 16
time ./a.out_int2str_T 100000000 >/dev/null 

