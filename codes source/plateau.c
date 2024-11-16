
















//
// Created by nathan on 03/11/2024.
//
int coord_x, coord_y;
#include <stdio.h>

#include "plateau.h"

int main() {

    initialisation_plateau();

    affichage_plateau();

    return 0;
}

#include <stdio.h>

#ifndef PLATEAU_H
#define PLATEAU_H

#define Taille_tableau 9
char plateau[Taille_tableau][Taille_tableau];

void initialisation_plateau() {
    for (int i = 0; i < Taille_tableau; i++) {
        for(int j = 0; j < Taille_tableau; j++) {
            plateau[i][j] = ' ';

        }
    }
}

void affichage_plateau() {
    for (int i = 0; i < Taille_tableau; i++) {
        for(int j = 0; j < Taille_tableau; j++){
            printf("%c ", plateau[i][j]);
        }
        printf("\n");
    }
}

#endif //PLATEAU_H