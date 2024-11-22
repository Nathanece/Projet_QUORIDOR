cmake_minimum_required(VERSION 3.29)
project(Code_QUORIDOR C)

set(CMAKE_C_STANDARD 23)

add_executable(Quoridor
        "codes_source/menu.c"
        "headers/joueur.h"
        "codes_source/plateau.c"
        headers/plateau.h
        "codes_source/joueur.c"
        main.c
        headers/menu.h
        "codes_source/score.c"
        "codes_source/score.c"
        "codes_source/joueur.c")