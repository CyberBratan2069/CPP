#!/usr/bin/env bash
########################################################################################################################
##                                                E N V I R O N M E N T                                               ##
########################################################################################################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
set -x
set -e


########################################################################################################################
##                                         C O M P I L E R  A N D  L I N K E R                                        ##
########################################################################################################################
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17 -Wno-unused-variable"

clang++ ${CPPFLAGS} \
  main_03_DATA.cpp \
  pascalString.cpp \
  -o main_03_DATA

clang++ ${CPPFLAGS} \
  main_colors.cpp \
  -o main_colors







# -> OLD
############################################
##            C O M P I L E R             ##
############################################
#HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
#CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
#clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/  -c pascalString.cpp
#clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/  -c main_colors.cpp
#clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/  -c main_03_DATA.cpp

############################################
##              L I N K E R               ##
############################################

#clang++ -o a.out_main_03_DATA main_03_DATA.o pascalString.o
#clang++ -o a.out_colors main_colors.o


