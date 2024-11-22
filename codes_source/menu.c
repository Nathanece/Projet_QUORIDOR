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
        if(deplacement == 1 && joueur[tour_joueur].coord_y==1) {
            deplacement=-1;
        }
        if(deplacement == 2 && joueur[tour_joueur].coord_y==9) {
            deplacement=-1;
        }
        if(deplacement == 3 && joueur[tour_joueur].coord_x==1) {
            deplacement=-1;
        }
        if(deplacement == 4 && joueur[tour_joueur].coord_x==9) {
            deplacement=-1;
        }
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
//ATTENTION, UTILISER LES LETTRES POUR PLACER LES BARRIERES COMME L'EXEMPLE DANS LE LIVRABLE
void poser_barriere(Barriere_plateau barrieres[20], Players joueur[], int *compteur_barriere, int tour_joueur) {
    // Récupération de la première case
    printf("Indiquez l'endroit ou poser la barriere.\n");
    do {
        printf("Case 1 (format B6, E9 ...) : ");
        scanf(" %2s", barrieres[*compteur_barriere].case1); // Lit les 2 caractères de la case (ex : E4)
    } while (barrieres[*compteur_barriere].case1[0] < 'A' || barrieres[*compteur_barriere].case1[0] > 'I' ||
             barrieres[*compteur_barriere].case1[1] < '1' || barrieres[*compteur_barriere].case1[1] > '9');

    // Récupération de la deuxième case
    do {
        printf("Case 2 (format : B6, E9 ...) : ");
        scanf(" %2s", barrieres[*compteur_barriere].case2); // Lit les deux caractères de la case (ex : E4)
        //Verification si c'est à une case d'écart (si même colonne ou même ligne avec une case d'écart au max)
    } while ((barrieres[*compteur_barriere].case2[0] < 'A' || barrieres[*compteur_barriere].case2[0] > 'I' ||
             barrieres[*compteur_barriere].case2[1] < '1' || barrieres[*compteur_barriere].case2[1] > '9') ||
        ((barrieres[*compteur_barriere].case2[0] != barrieres[*compteur_barriere].case1[0] &&
              barrieres[*compteur_barriere].case2[1] != barrieres[*compteur_barriere].case1[1]) ||
             abs(barrieres[*compteur_barriere].case2[0] - barrieres[*compteur_barriere].case1[0]) +
             abs(barrieres[*compteur_barriere].case2[1] - barrieres[*compteur_barriere].case1[1]) != 1));

    // Choix du côté
    if (barrieres[*compteur_barriere].case1[0] == barrieres[*compteur_barriere].case2[0]) {
        // Affichage en colonne
        do {
            printf("Cote ('g' gauche, 'd' droit) : ");
            scanf(" %c", &barrieres[*compteur_barriere].cote);
        } while (barrieres[*compteur_barriere].cote != 'g' && barrieres[*compteur_barriere].cote != 'd');
    } else {
        // Affichage en ligne
        do {
            printf("Cote ('h' haut, 'b' bas) : ");
            scanf(" %c", &barrieres[*compteur_barriere].cote);
        } while (barrieres[*compteur_barriere].cote != 'h' && barrieres[*compteur_barriere].cote != 'b');
    }

    // Mise à jour du compteur et des barrières du joueur
    joueur[tour_joueur].barriere--;
    (*compteur_barriere)++;
    printf("%s %s %c", barrieres[*compteur_barriere].case1, barrieres[*compteur_barriere].case2, barrieres[*compteur_barriere].cote);
}

//Menu affichant les actions possibles.
void menu_action(int tour_joueur, Players joueur[], int nb_joueurs, Barriere_plateau barrieres[], int *compteur_barriere) {
    int action;
    int fin = 0;
    do {
        //Choix de l'action selon l'affichage
        do {
            //Sauvegarde des informations du jeu (positions, joueurs, ...)
            sauvegarde_plateau(joueur, nb_joueurs, tour_joueur, *compteur_barriere, barrieres);

            //Affichage du tableau
            affichage_plateau(nb_joueurs, joueur, *compteur_barriere, barrieres);

            //Initialisation couleur
            Color(15, 0);
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
            case 2:
                poser_barriere(barrieres, joueur, compteur_barriere, tour_joueur);
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