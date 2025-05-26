#!/usr/bin/env bash

############################################
##          E N V I R O N M E N T         ##
############################################

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"

echo -e "\033[01;35m******************************************************************************\033[0m"
UTIL_PATH_PATH="../90_aux_src"
alias ld="clang++"       # easy invokation of linker ld
shopt -s expand_aliases  # use alias in this script
set -e                   # exit if command returns error


############################################
##        S Y N T A X  C H E C K          ##
############################################
set -x                   # print commands
clang++ ${CPPFLAGS} -I ${UTIL_PATH_PATH}/helpers -fsyntax-only -c constants.hpp
clang++ ${CPPFLAGS} -I ${UTIL_PATH_PATH}/helpers -fsyntax-only -c 1.hpp

############################################
##            C O M P I L E R             ##
############################################

function compile () {
  echo "compiling ${CPP_FILE}"
  clang++ ${CPPFLAGS} -I ${UTIL_PATH_PATH}/helpers -c ${CPP_FILE}
}

set +x                   # do not print commands
echo -e "\033[01;34m============== compiling ... ==============\033[0m"
echo "using ${CPPFLAGS} -I ${UTIL_PATH_PATH}/helpers"

CPP_FILE="1.cpp"
compile

CPP_FILE="main.cpp"
compile


############################################
##              L I N K E R               ##
############################################

echo -e "\033[01;34m============== linking ... ==============\033[0m"
set -x                   # print commands
ld -o a.out_skel main.o 1.o



