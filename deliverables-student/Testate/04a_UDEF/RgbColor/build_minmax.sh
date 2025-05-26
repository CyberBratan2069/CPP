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
##             I N T E G E R              ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_int.out        I N T E G E R"
clang++  ${CPPFLAGS} -DCALCTYPE_INT -I${HEADER_PATH}/helpers/ -c main_04_UDEF_minmax.cpp
clang++ -o a.out_minmax_int main_04_UDEF_minmax.o


############################################
##              D O U B L E               ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_double.out     D O U B L E"
clang++  ${CPPFLAGS} -DCALCTYPE_DOUBLE -I${HEADER_PATH}/helpers/ -c main_04_UDEF_minmax.cpp
clang++ -o a.out_minmax_double main_04_UDEF_minmax.o


############################################
##            R A T I O N A L             ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_rational.out   R A T I O N A L"
clang++  ${CPPFLAGS} -c RationalNumber.cpp
clang++  ${CPPFLAGS} -DCALCTYPE_RATIONAL -I${HEADER_PATH}/helpers/ -c  main_04_UDEF_minmax.cpp
clang++ -o a.out_minmax_rational RationalNumber.o main_04_UDEF_minmax.o


############################################
##               R G B                    ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_rational.out   R G B"
clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c RgbColor.cpp
clang++ ${CPPFLAGS} -DCALCTYPE_RGB -I${HEADER_PATH}/helpers/ -c main_04_UDEF_minmax.cpp
clang++ -o a.out_minmax_rgb RgbColor.o main_04_UDEF_minmax.o

#echo -en "\033[01;31mTODO: \033[0m"
#echo "FIXME - TODO - TBD - AUFGABE RGB!"
#clang++ -o a.out_minmax_rgb missingObjectFile.o



