#!/usr/bin/env bash
############################################
##          E N V I R O N M E N T         ##
############################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
set -e
set -x


############################################
##            C O M P I L E R             ##
############################################

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c ${HEADER_PATH}/helpers/AnsiConsole.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c shapes_main.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c shapes.cpp
#clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c main_cycle.cpp


############################################
##              L I N K E R               ##
############################################

clang++ -o a.out_shape_main AnsiConsole.o shapes_main.o shapes.o
#clang++ -o a.out_cycle main_cycle.o






