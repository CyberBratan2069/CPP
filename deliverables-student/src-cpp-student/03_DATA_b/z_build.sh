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
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/  -c z_aggregates.cpp
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/  -c z_printlnDemo_cmplx.cpp

############################################
##              L I N K E R               ##
############################################


clang++ -o a.out_z_aggregates z_aggregates.o
clang++ -o a.out_z_printlnDemo_cmplx z_printlnDemo_cmplx.o


