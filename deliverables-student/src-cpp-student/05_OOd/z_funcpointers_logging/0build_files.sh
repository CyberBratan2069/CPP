#!/usr/bin/env bash
set -eux
awk '/\/\/MPINCLUDE1/{flag=1; next} /\/\/MPINCLUDE2/{flag=0} flag' main.cpp > main_frag_a.cpp
awk '/\/\/MPINCLUDE3/{flag=1; next} /\/\/MPINCLUDE4/{flag=0} flag' main.cpp >> main_frag_a.cpp

awk '/\/\/MPINCLUDE1/{flag=1; next} /\/\/MPINCLUDE2/{flag=0} flag' logger.cpp > logger_frag_a.cpp
awk '/\/\/MPINCLUDE3/{flag=1; next} /\/\/MPINCLUDE4/{flag=0} flag' logger.cpp >> logger_frag_a.cpp
awk '/\/\/MPINCLUDE5/{flag=1; next} /\/\/MPINCLUDE6/{flag=0} flag' logger.cpp >> logger_frag_a.cpp
awk '/\/\/MPINCLUDE7/{flag=1; next} /\/\/MPINCLUDE8/{flag=0} flag' logger.cpp >> logger_frag_a.cpp

