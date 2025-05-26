cmake_minimum_required(VERSION 3.28)
project(Cpp)

set(CMAKE_CXX_STANDARD 26)

add_executable(Cpp main.cpp
        deliverables-student/src-cpp-student/04a_UDEF/mods/main_rgbColor.cpp
        deliverables-student/src-cpp-student/04a_UDEF/mods/RgbColor.cpp
        deliverables-student/src-cpp-student/03_DATA_a/mods/z_limits_dataVars.cpp
        deliverables-student/src-cpp-student/03_DATA_a/z_printlnDemo.cpp
        deliverables-student/src-cpp-student/03_DATA_b/main_03_DATA.cpp
        deliverables-student/Testate/03_DATA_a/DataVars.cpp
        deliverables-student/Testate/04a_UDEF/Vektor2D/Vektor2D.h
        deliverables-student/Testate/04a_UDEF/RgbColor/RgbColor.cpp
        deliverables-student/Testate/04a_UDEF/RgbColor/main_rgbColor.cpp
        deliverables-student/src-cpp-student/01_TOOL/z_implDecl/main.c
        deliverables-student/Testate/07_IO/z_match_main.cpp
)
