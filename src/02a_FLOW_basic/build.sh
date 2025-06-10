#!/usr/bin/env bash
########################################################################################################################
##                                                E N V I R O N M E N T                                               ##
########################################################################################################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
set -e
set -x

########################################################################################################################
##                                         C O M P I L E R  A N D  L I N K E R                                        ##
########################################################################################################################
# shellcheck disable=SC2034
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17 -Wno-unused-variable"

clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ mods.cpp \
                      ${HEADER_PATH}/helpers/AnsiConsole.cpp \
                      ${HEADER_PATH}/helpers/printSteps.cpp \
                      -o mods

clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ mods01.cpp \
                      ${HEADER_PATH}/helpers/AnsiConsole.cpp \
                      ${HEADER_PATH}/helpers/printSteps.cpp \
                      -o mods01

clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ mods02.cpp \
                      ${HEADER_PATH}/helpers/AnsiConsole.cpp \
                      ${HEADER_PATH}/helpers/printSteps.cpp \
                      -o mods02

clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ mods03.cpp \
                      ${HEADER_PATH}/helpers/AnsiConsole.cpp \
                      ${HEADER_PATH}/helpers/printSteps.cpp \
                      -o mods03

clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ mods04.cpp \
                      ${HEADER_PATH}/helpers/AnsiConsole.cpp \
                      ${HEADER_PATH}/helpers/printSteps.cpp \
                      -o mods04

#New build.sh file
#chmod +x build.sh
