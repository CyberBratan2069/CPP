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

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"


############################################
##                                ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building ..."

clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -I../04_UDEF/ -c z_match_elements.cpp
clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -I../04_UDEF/ -c z_match_patterns.cpp
clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -I../04_UDEF/ -c z_match_main.cpp

clang++ -o a.out_hello z_match_main.o z_match_elements.o z_match_patterns.o

clang++ -o a.out_cout z_main_cout.cpp 
