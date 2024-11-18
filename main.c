#include "headers/joueur.h"
#include "headers/menu.h"
#include "headers/plateau.h"

int main() {
    int nb_joueurs;
    Players joueur[4];//La structure de chacun des joueurs sera dans ce tableau
    initialisation_joueurs(joueur, &nb_joueurs);
    int aleatoire = tirage_au_sort(nb_joueurs);
    menu_action(aleatoire, joueur, nb_joueurs);
    return 0;
}