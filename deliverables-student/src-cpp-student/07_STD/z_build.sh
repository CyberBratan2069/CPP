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
##               Templated                ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_rational.out   R G B"

clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -I../04_UDEF/ -c ../04_UDEF/RationalNumber.cpp
clang++  ${CPPFLAGS} -I${HEADER_PATH}/helpers -I../04_UDEF/ -c z_main_minmax_T.cpp

clang++ -o a.out_minmax_T RationalNumber.o  z_main_minmax_T.o

set +x
set +e
echo "============================ diffing minmax.cpp =========================="
diff -Bwy --left-column   ../04_UDEF/main_04_UDEF_minmax.cpp z_main_minmax_T.cpp 
echo "============================ diffing build.sh ============================"
diff -Bwy --left-column  ../04_UDEF/build_minmax.sh  z_build.sh
echo "============================                  ============================"


