#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/menu.h"
#include "../headers/joueur.h"
#include "../headers/plateau.h"

//Fonction permettant de choisir le tour du premier joueur au hasard
int tirage_au_sort(int nb_joueurs) {
    srand(time(NULL));
    return rand() % nb_joueurs; //Indique quel joueur commence
}

//FONCTION de déplacement du pion
void deplacer_pion(int tour_joueur, Players joueur[]) {
    int deplacement;
    //Choix du déplacement du pion
    do {
        printf("Ou voulez vous aller ?\n"
               "-1 'Haut'\n-2 'Bas'\n-3 'Gauche'\n-4 'Droite'\n");
        scanf(" %d", &deplacement);
        //Blindage de la saisie
    } while(deplacement < 0 || deplacement > 4);
    //Cas de déplacement
    switch(deplacement) {
        case 1: //Aller en haut (il semble que je doive faire diminuer cette valeur)
            joueur[tour_joueur].coord_y--;
        break;
        case 2: //Aller en bas (même remarque que haut à l'inverse)
            joueur[tour_joueur].coord_y++;
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

//Fonction stockant les barrières placées
//ATTENTION, UTILISER LES LETTRES POUR PLACER LES BARRIERES COMME INDQUE DANS LE LIVRABLE
void poser_barriere(int tab_barriere[20][4]) {

}


//Menu affichant les actions possibles.
void menu_action(int tour_joueur, Players joueur[], int nb_joueurs) {
    int action;
    int fin = 0;
    do {
        //Choix de l'action selon l'affichage
        do {
            //Sauvegarde des informations du jeu (positions, joueurs, ...)
            sauvegarde_plateau(joueur, nb_joueurs);

            //Affichage du tableau
            affichage_plateau(nb_joueurs, joueur);

            //Affichage du pseudo du joueur avec sa couleur associée
            printf("\nC'est le tour de");
            Color(joueur[tour_joueur].couleur, 0);
            printf(" %s\n", joueur[tour_joueur].nom);
            //Remise à la couleur originale
            Color(15, 0);
            printf("Quelle action voulez vous faire ?\n"
                   "-1 Deplacer son pion\n"
                   "-2 Poser une barriere\n"
                   "-3 Passer son tour\n"
                   "-4 Annuler la derniere action\n");
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

        //Permet de changer de tour (en fonction du nombre de joueurs
        tour_joueur = ++tour_joueur%nb_joueurs;
    }while(1);
}

//MENU DE DEPART. Il est affiché au tout début du jeu
int menu() {
    int choix;
    do {
        printf("Que voulez vous faire ?\n"
               "-1 Lancer une nouvelle partie\n"
               "-2 Reprendre une partie sauvegardee\n"
               "-3 Afficher l'aide\n"
               "-4 Afficher le score des joueurs\n"
               "-5 Quitter le jeu\n");
        scanf(" %d", &choix);
    } while (choix < 1 || choix > 6);
    return choix;
}