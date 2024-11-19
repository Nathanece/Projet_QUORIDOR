#include "headers/joueur.h"
#include "headers/menu.h"
#include "headers/plateau.h"
#include <stdio.h>

int main() {
    int nb_joueurs = 0;
    Players joueur[4];//La structure de chacun des joueurs sera dans ce tableau
    int choix = menu();
    switch(choix) {
        case 1:
            initialisation_joueurs(joueur, &nb_joueurs);
        break;
        case 2:
            chargement_plateau(joueur, &nb_joueurs);
        break;
        default:
            break;
    }
    int aleatoire = tirage_au_sort(nb_joueurs);
    menu_action(aleatoire, joueur, nb_joueurs);
    return 0;
}