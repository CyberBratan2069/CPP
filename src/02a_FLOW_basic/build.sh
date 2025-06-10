#!/usr/bin/env bash

echo -e "\033[01;34m============== building ... ==============\033[0m"
set -e
set -x

# shellcheck disable=SC2034
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17 -Wno-unused-variable"

#clang++ ${CPPFLAGS} ${INCLUDES} mods.cpp ${COMMON_SRC} -o mods
#clang++ ${CPPFLAGS} ${INCLUDES} mods01.cpp ${COMMON_SRC} -o mods01
#clang++ ${CPPFLAGS} ${INCLUDES} mods02.cpp ${COMMON_SRC} -o mods02
#clang++ ${CPPFLAGS} ${INCLUDES} mods03.cpp ${COMMON_SRC} -o mods03
#clang++ ${CPPFLAGS} ${INCLUDES} mods04.cpp ${COMMON_SRC} -o mods04

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
