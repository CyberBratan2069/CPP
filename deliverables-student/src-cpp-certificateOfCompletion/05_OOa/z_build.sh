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
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c z_AnsiConsoleDemo.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c z_main_vehicles.cpp
#clang++ ${CPPFLAGS} -I${UTIL_PATH_PATH}/helpers/ -c z_main_value_entity.cpp

############################################
##              L I N K E R               ##
############################################

clang++ -o a.out_z_ansiConsoleDemo AnsiConsole.o z_AnsiConsoleDemo.o
clang++ -o a.out_z_vehicles z_main_vehicles.o
#clang++ -o a.out_z_value_entity z_main_value_entity.o





