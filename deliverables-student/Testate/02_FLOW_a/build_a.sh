#!/usr/bin/env bash
############################################
##          E N V I R O N M E N T         ##
############################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../../90_aux_src}
set -e
set -x

############################################
##            C O M P I L E R             ##
############################################

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17 -Wno-unused-variable"
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c ${HEADER_PATH}/helpers/AnsiConsole.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c ${HEADER_PATH}/helpers/printSteps.cpp
#clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c main_03_FLOW_a.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c mods.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c mods01.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c mods02.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c mods03.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c mods04.cpp


############################################
##              L I N K E R               ##
############################################

#clang++ -o a.out_03_FLOW_a AnsiConsole.o printSteps.o main_03_FLOW_a.o
clang++ -o a.out_mods AnsiConsole.o printSteps.o mods.o
clang++ -o a.out_mods01 AnsiConsole.o printSteps.o mods01.o
clang++ -o a.out_mods02 AnsiConsole.o printSteps.o mods02.o
clang++ -o a.out_mods03 AnsiConsole.o printSteps.o mods03.o
clang++ -o a.out_mods04 AnsiConsole.o printSteps.o mods04.o


