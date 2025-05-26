#!/usr/bin/env bash


if [[ -z $1 ]]; then     # make sure we have a file name
  echo "usage: ./tool_c_to_out.sh file.c"
  exit 1
fi

IN_NAME=$1
OUT_NAME="$(basename $1 .c).out"
echo transforming " .c to a.out: "  $IN_NAME to $OUT_NAME
set -x                   # let bash print the following commands
clang -o $OUT_NAME $IN_NAME
