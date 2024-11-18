#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/menu.h"
#include "../headers/joueur.h"
#include "../headers/plateau.h"

int menu() {
    int choix;
    do {
        printf("Que voulez vous faire ?\n"
               "-1 Lancer une nouvelle partie\n"
               "-2 Reprendre une partie sauvegardée\n"
               "-3 Afficher l'aide\n"
               "-4 Afficher le score des joueurs\n"
               "-5 Quitter le jeu\n");
        scanf(" %d", &choix);
    } while (choix < 1 || choix > 6);
    return choix;
}

int tirage_au_sort(int nb_joueurs) {
    srand(time(NULL));
    return rand() % nb_joueurs + 1; //Indique quel joueur commence
}

void deplacer_pion(int tour_joueur, Players joueur[]) {
    int deplacement;
    //Choix du déplacement du pion
    do {
        printf("Ou voulez vous aller ?\n"
               "-1 'Haut'\n-2 'Bas'\n-3 'Gauche'\n-4 'Droite'\n");
        scanf(" %d", &deplacement);
    } while(deplacement < 0 || deplacement > 4);
    switch(deplacement) {
        case 1: //Aller en haut
            joueur[tour_joueur].coord_y++;
        break;
        case 2: //Aller en bas
            joueur[tour_joueur].coord_y--;
        break;
        case 3: //Aller a gauche
            joueur[tour_joueur].coord_x--;
        break;
        case 4: //Aller a droite
            joueur[tour_joueur].coord_x++;
        break;
        default:
            break;
    }
}

void poser_barriere() {

}


//La valeur retournée par rotation_joueur est utilisée à la place de 'tour_joueur'
void menu_action(int tour_joueur, Players joueur[], int nb_joueurs) {
    int action;
    int fin = 0;
    do {
        //Choix de l'action selon l'affichage
        do {
            printf("C'est le tour de '%s'\n"
                   "Quelle action voulez vous faire ?\n"
                   "-1 Deplacer son pion\n"
                   "-2 Poser une barriere\n"
                   "-3 Passer son tour\n"
                   "-4 Annuler la derniere action\n", joueur[tour_joueur].nom);
            scanf(" %d", &action);
        }while (action < 1 || action > 4);
        //L'action réalisée en fonction du choix du joueur
        switch(action) {
            case 1: //Deplacement du pion
                deplacer_pion(tour_joueur, joueur);
            break;
            default:
                break;
        }
        //Sauvegarde des informations du joueur après sont action
        sauvegarde_plateau(joueur, nb_joueurs);
        //Permet de changer de tour (de 0 à 3)
        tour_joueur = ++tour_joueur%4;
    }while(1);
}