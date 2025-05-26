#!/usr/bin/env bash
#
# make sure we have a file name as first parameter
if [[ -z $1 ]]; then
  echo "usage: ./tool_c_to_out.sh <name of C file>"
  exit 1
fi
#
#

IN_NAME=$1
OUT_NAME="$1.out"
echo "compiling a single .c file to .out: "  $IN_NAME to $OUT_NAME
set -x                   # let bash print the following commands
clang -o $OUT_NAME $IN_NAME
