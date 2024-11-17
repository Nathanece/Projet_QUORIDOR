#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/menu.h"
#include "../headers/joueur.h"

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

//Fait varier le tour des joueurs (de 0 à 3).
int rotation_joueur(int aleatoire) {
    return ++aleatoire%4;
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
            joueur[tour_joueur].coordonnee_y++;
        break;
        case 2: //Aller en bas
            joueur[tour_joueur].coordonnee_y--;
        break;
        case 3: //Aller a gauche
            joueur[tour_joueur].coordonnee_x--;
        break;
        case 4: //Aller a droite
            joueur[tour_joueur].coordonnee_x++;
        break;
        default:
            break;
    }
}

void poser_barriere() {

}


//La valeur retournée par rotation_joueur est utilisée à la place de 'tour_joueur'
int menu_action(int tour_joueur, Players joueur[]) {
    int action;
    do {
        printf("C'est le tour de '%s'\n"
               "Quelle action voulez vous faire ?\n"
               "-1 Deplacer son pion\n"
               "-2 Poser une barriere\n"
               "-3 Passer son tour\n"
               "-4 Annuler la derniere action\n", joueur[tour_joueur].nom);
        scanf(" %d", &action);
    }while (action < 1 || action > 4);
    switch(action) {
        case 1:
            deplacer_pion(tour_joueur, joueur);
        break;
        default:
            break;
    }
}