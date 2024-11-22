#include "headers/joueur.h"
#include "headers/menu.h"
#include "headers/plateau.h"

int main() {
    //Initialisation des variables
    int nb_joueurs = 0;
    int tour_joueur = 0;
    int compteur_barrieres = 0;
    Players joueur[4];//La structure de chacun des joueurs sera dans ce tableau
    Barriere_plateau barrieres[20];
    //Appel du menu principal
    int choix = menu();
    //Les fonctions à appeler en fonction du choix de l'utilisateur
    switch(choix) {
        case 1:
            initialisation_joueurs(joueur, &nb_joueurs);
            tour_joueur = tirage_au_sort(nb_joueurs);
        break;
        case 2:
            chargement_plateau(joueur, &nb_joueurs, &tour_joueur, &compteur_barrieres, barrieres);
        break;
        default:
            break;
    }
    //Appel du menu d'action
    menu_action(tour_joueur, joueur, nb_joueurs, barrieres, &compteur_barrieres);
    return 0;
}