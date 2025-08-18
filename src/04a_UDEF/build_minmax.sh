#!/usr/bin/env bash
########################################################################################################################
##                                                E N V I R O N M E N T                                               ##
########################################################################################################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
HEADER_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
set -e                     # exit on first error
set -x


########################################################################################################################
##                                                   C O M P I L E R                                                  ##
########################################################################################################################
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"


########################################################################################################################
##                                                    I N T E G E R                                                   ##
########################################################################################################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building out_minmax_int        I N T E G E R"

clang++  ${CPPFLAGS} -DCALCTYPE_INT \
  main_04_UDEF_minmax.cpp \
  -o out_minmax_int

# -> old
#clang++  ${CPPFLAGS} -DCALCTYPE_INT -I${HEADER_PATH}/helpers/ -c main_04_UDEF_minmax.cpp
#clang++ -o a.out_minmax_int main_04_UDEF_minmax.o


########################################################################################################################
##                                                     D O U B L E                                                    ##
########################################################################################################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building out_minmax_double     D O U B L E"

clang++  ${CPPFLAGS} -DCALCTYPE_DOUBLE \
  main_04_UDEF_minmax.cpp \
  -o out_minmax_double

# -> old
#clang++  ${CPPFLAGS} -DCALCTYPE_DOUBLE -I${HEADER_PATH}/helpers/ -c main_04_UDEF_minmax.cpp
#clang++ -o a.out_minmax_double main_04_UDEF_minmax.o


########################################################################################################################
##                                                   R A T I O N A L                                                  ##
########################################################################################################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building out_minmax_rational   R A T I O N A L"

clang++  ${CPPFLAGS} -DCALCTYPE_RATIONAL \
  main_04_UDEF_minmax.cpp \
  RationalNumber.cpp \
  -o out_minmax_rational

# -> old
#clang++  ${CPPFLAGS} -c RationalNumber.cpp
#clang++  ${CPPFLAGS} -DCALCTYPE_RATIONAL -I${HEADER_PATH}/helpers/ -c  main_04_UDEF_minmax.cpp
#clang++ -o a.out_minmax_rational RationalNumber.o main_04_UDEF_minmax.o


########################################################################################################################
##                                                        R G B                                                       ##
########################################################################################################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building out_minmax_rgb        R G B"

clang++ ${CPPFLAGS} -DCALCTYPE_RGB \
  main_04_UDEF_minmax.cpp \
  RgbColor.cpp \
  -o out_minmax_rgb

# -> old
#clang++ ${CPPFLAGS} -I${HEADER_PATH}/helpers/ -c RgbColor.cpp
#clang++ ${CPPFLAGS} -DCALCTYPE_RGB -I${HEADER_PATH}/helpers/ -c main_04_UDEF_minmax.cpp
#clang++ -o a.out_minmax_rgb RgbColor.o main_04_UDEF_minmax.o

#echo -en "\033[01;31mTODO: \033[0m"
#echo "FIXME - TODO - TBD - AUFGABE RGB!"
#clang++ -o a.out_minmax_rgb missingObjectFile.o

########################################################################################################################
##                                                        A L L                                                       ##
########################################################################################################################
echo -en "\033[01;34minfo: \033[0m"
echo "building out_minmax_all   A L L"

cat > out_minmax_all <<'EOF'
#!/usr/bin/env bash
set -euo pipefail

# Farben
blue='\033[01;34m'
green='\033[01;32m'
red='\033[01;31m'
nc='\033[0m'

run_bin() {
  local title="$1" bin="$2"
  if [[ ! -x "$bin" ]]; then
    printf "${red}Fehler:${nc} %s nicht gefunden oder nicht ausführbar.\n" "$bin" >&2
    exit 1
  fi
  printf "${blue}%s${nc}\n" "$title"
  "./$bin"
}

run_bin "I N T E G E R"   "out_minmax_int"
run_bin "D O U B L E"     "out_minmax_double"
run_bin "R A T I O N A L" "out_minmax_rational"
run_bin "R G B"           "out_minmax_rgb"
EOF

chmod +x out_minmax_all



