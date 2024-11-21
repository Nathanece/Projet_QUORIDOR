cmake_minimum_required(VERSION 3.29)
project(Code_QUORIDOR C)

set(CMAKE_C_STANDARD 23)

add_executable(Quoridor
        "codes source/menu.c"
        "headers/joueur.h"
        "codes source/plateau.c"
        headers/plateau.h
        "codes source/joueur.c"
        main.c
        headers/menu.h
        "codes source/score"
        "codes source/score")