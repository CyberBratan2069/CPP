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


############################################
##            R G B - Vorlage             ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_rgbColor.out          RGB Vorlage"
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c RgbColor.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c main_rgbColor.cpp
clang++ -o a.out_z_rgbColor  main_rgbColor.o RgbColor.o




