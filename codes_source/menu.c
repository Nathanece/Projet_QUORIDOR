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
void deplacer_pion(int tour_joueur, Players joueur[], int nb_joueurs, int compteur_barrieres, Barriere_plateau barrieres[]) {
    int deplacement;
    int pos_i_x = joueur[tour_joueur].coord_x, pos_i_y = joueur[tour_joueur].coord_y;
    int pos_f_x = pos_i_x, pos_f_y = pos_i_y;
    //Choix du déplacement du pion
    do {
        printf("Ou voulez vous aller ?\n"
               "-1 'Haut'\n-2 'Bas'\n-3 'Gauche'\n-4 'Droite'\n");
        scanf(" %d", &deplacement);
        //Cas de déplacement
        switch(deplacement) {
            case 1: //Aller en haut (il semble que je doive faire diminuer cette valeur)
                pos_f_y--;
                break;
            case 2: //Aller en bas (même remarque que haut à l'inverse)
                pos_f_y++;
                break;
            case 3: //Aller a gauche
                pos_f_x--;
            break;
            case 4: //Aller a droite
                pos_f_x++;
            break;
            default:
                deplacement=-3; // erreur de saisie
                break;
        }
        //blindage sortie de terrain;
        if(pos_f_x<=0 || pos_f_y<=0 || pos_f_x>=10 || pos_f_y>=10) { deplacement=-2; }

        // blindage barriere
        switch(deplacement) {
            case 1://haut
                for (int i = 0; i < compteur_barrieres; i++) {
                    int case1_x = barrieres[i].case1[0]-'A'+1,
                        case1_y = barrieres[i].case1[1]-'0',
                        case2_x = barrieres[i].case2[0]-'A'+1,
                        case2_y = barrieres[i].case2[1]-'0';
                    // blocage passage barriere horizontale bas 1ere case
                    if(pos_i_x==case1_x && pos_i_y==case1_y+1
                            && barrieres[i].cote=='b') { deplacement=-1; }
                    // blocage passage barriere horizontale bas 2e case
                    if(pos_i_x==case2_x && pos_i_y==case2_y+1
                            && barrieres[i].cote=='b') { deplacement=-1; }
                    // blocage passage barriere horizontale haut 1ere case
                    if(pos_i_x==case1_x && pos_i_y==case1_y
                            && barrieres[i].cote=='h') { deplacement=-1; }
                    // blocage passage barriere horizontale haut 2e case
                    if(pos_i_x==case2_x && pos_i_y==case2_y
                            && barrieres[i].cote=='h') { deplacement=-1; }
                }
               break;
            case 2://bas
                for (int i = 0; i < compteur_barrieres; i++) {
                    int case1_x = barrieres[i].case1[0]-'A'+1,
                        case1_y = barrieres[i].case1[1]-'0',
                        case2_x = barrieres[i].case2[0]-'A'+1,
                    case2_y = barrieres[i].case2[1]-'0';
                    // blocage passage barriere horizontale bas 1ere case
                    if(pos_i_x==case1_x && pos_i_y==case1_y
                            && barrieres[i].cote=='b') { deplacement=-1; }
                    // blocage passage barriere horizontale bas 2e case
                    if(pos_i_x==case2_x && pos_i_y==case2_y
                            && barrieres[i].cote=='b') { deplacement=-1; }
                    // blocage passage barriere horizontale haut 1ere case
                    if(pos_i_x==case1_x && pos_i_y==case1_y-1
                            && barrieres[i].cote=='h') { deplacement=-1; }
                    // blocage passage barriere horizontale haut 2e case
                    if(pos_i_x==case2_x && pos_i_y==case2_y-1
                            && barrieres[i].cote=='h') { deplacement=-1; }
                }
                break;
            case 3://gauche
                for (int i = 0; i < compteur_barrieres; i++) {
                    int case1_x = barrieres[i].case1[0]-'A'+1,
                        case1_y = barrieres[i].case1[1]-'0',
                        case2_x = barrieres[i].case2[0]-'A'+1,
                        case2_y = barrieres[i].case2[1]-'0';
                    // blocage passage barriere verticale gauche 1ere case
                    if(pos_i_x==case1_x && pos_i_y==case1_y
                            && barrieres[i].cote=='g') { deplacement=-1; }
                    // blocage passage barriere verticale gauche 2e case
                    if(pos_i_x==case2_x && pos_i_y==case2_y
                            && barrieres[i].cote=='g') { deplacement=-1; }
                    // blocage passage barriere verticale droite 1ere case
                    if(pos_i_x==case1_x+1 && pos_i_y==case1_y
                            && barrieres[i].cote=='d') { deplacement=-1; }
                    // blocage passage barriere verticale droite 2e case
                    if(pos_i_x==case2_x+1 && pos_i_y==case2_y
                            && barrieres[i].cote=='d') { deplacement=-1; }
                }
                break;
            case 4://droite
            for (int i = 0; i < compteur_barrieres; i++) {
                int case1_x = barrieres[i].case1[0]-'A'+1,
                    case1_y = barrieres[i].case1[1]-'0',
                    case2_x = barrieres[i].case2[0]-'A'+1,
                    case2_y = barrieres[i].case2[1]-'0';
                // blocage passage barriere verticale gauche 1ere case
                if(pos_i_x==case1_x-1 && pos_i_y==case1_y
                        && barrieres[i].cote=='g') { deplacement=-1; }
                // blocage passage barriere verticale gauche 2e case
                if(pos_i_x==case2_x-1 && pos_i_y==case2_y
                        && barrieres[i].cote=='g') { deplacement=-1; }
                // blocage passage barriere verticale droite 1ere case
                if(pos_i_x==case1_x && pos_i_y==case1_y
                        && barrieres[i].cote=='d') { deplacement=-1; }
                // blocage passage barriere verticale droite 2e case
                if(pos_i_x==case2_x && pos_i_y==case2_y
                        && barrieres[i].cote=='d') { deplacement=-1; }
            }
            break;
        }

        //cas d'un joueur déjà présent sur la case
        for(int i = 0; i < nb_joueurs; i++) {
            if (deplacement>0 && i!=tour_joueur && pos_f_x == joueur[i].coord_x && pos_f_y == joueur[i].coord_y) {
                deplacement=-4;
            }
        }
        switch(deplacement) {
            case -1:
                Color(3, 0);
                printf("Vous ne pouvez effectuer cette action car il y a une barriere\n");
                Color(15, 0);
                //reinitialisation du mouvement du joueur
                pos_f_x=pos_i_x;
                pos_f_y=pos_i_y;
                break;
            case -2:
                Color(3, 0);
                printf("Vous ne pouvez effectuer cette action car vous etes au bord du terrain\n");
                Color(15, 0);
                //reinitialisation du mouvement du joueur
                pos_f_x=pos_i_x;
                pos_f_y=pos_i_y;
                break;
            case -3:
                Color(3, 0);
                printf("Valeur saisie non autorisee !\n");
                Color(15, 0);
                break;
            case -4:
                Color(3, 0);
                printf("Un joueur est present sur cette case.\n");
                Color(15, 0);
                //reinitialisation de la position initiale du joueur
                pos_i_x=pos_f_x;
                pos_i_y=pos_f_y;
                break;
        }
    } while(deplacement < 0 || deplacement > 4);
    //met à jour la nouvelle position du joueur
    joueur[tour_joueur].coord_x = pos_f_x;
    joueur[tour_joueur].coord_y = pos_f_y;
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
int menu_action(int tour_joueur, Players joueur[]) {
    int action;
    //Choix de l'action selon l'affichage
    do {
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
    } while (action < 1 || action > 4);
    return action;
}

//Fonction permettant de changer de tour (en fonction du nombre de joueurs
void changement_tour(int* tour_joueur, int nb_joueurs) {
    *tour_joueur = ++(*tour_joueur) % nb_joueurs;
}

//Affichage de la fiche d'aide expliquant comment jouer
void fiche_aide() {
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


void afficher_scores() {
    // Ouverture du fichier contenant les scores en mode lecture
    FILE *fichier = fopen("../scores.txt", "r");

    // Vérifie si le fichier est accessible
    if (fichier == NULL) {
        printf("Aucun score enregistré pour le moment.\n");
        return;
    }

    // Variables temporaires pour stocker les données lues
    char nom_temp[pseudo];
    int score_temp;

    // Affiche un en-tête pour les scores
    printf("Scores des joueurs :\n");

    // Lecture des scores ligne par ligne
    while (fscanf(fichier, "%s %d\n", nom_temp, &score_temp) != EOF) {
        // Affiche le nom et le score du joueur
        printf("%s : %d points\n", nom_temp, score_temp);
    }

    // Fermeture du fichier après lecture
    fclose(fichier);
}
