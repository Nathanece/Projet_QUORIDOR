#include <stdio.h>
#include "../headers/joueur.h"
#include "../headers/plateau.h"
#include <windows.h>
//Taille du tableau (carré 9x9)
#define TAILLE_TABLEAU 9

/////////// PROTOTYPES DES SOUS-PROGRAMMES
void Color(int couleurDuTexte,int couleurDeFond);
///////////////////////////////////////
// Nom du sous-programme : COLOR
// Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Compatibilité : Windows
///////////////////////////////////////
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoligcol(int lig, int col) {
    //Ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

//Sauvegarde des barrieres (nb de barrieres et coordonnées)
void sauvegarde_barrieres(int compteur_barriere, Barriere_plateau barriere[]) {
    FILE* fplateau = fopen("../barriere.txt", "w");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }
    //Enregistrement du nombre de barrieres placées
    fprintf(fplateau, "%d \n", compteur_barriere);

    //Enregistrement des coordonnées de chaques barrieres
    for (int i = 0; i < compteur_barriere; i++) {
        fprintf(fplateau, "%s %s %c \n",
            barriere[i].case1, barriere[i].case2, barriere[i].cote);
    }
    fclose(fplateau);
}

//Sauvegarde des coordonnées des joueurs
void sauvegarde_coord_joueurs(Players joueur[], int nbjoueurs) {
    FILE* fplateau = fopen("../coord_joueurs.txt", "w");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }

    //Enregistrement des coordonnées des joueurs
    for (int i = 0; i < nbjoueurs; i++) {
        fprintf(fplateau, "%d %d\n",
            joueur[i].coord_x, joueur[i].coord_y);
    }
    fclose(fplateau);
}

//Sauvegarde des informations initiales du joueurs
void sauvegarde_info_joueurs(Players joueur[], int nbjoueurs, int tour_joueur) {
    FILE* fplateau = fopen("../infos_joueurs.txt", "w");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }

    //Enregistrement du nombre de joueurs
    fprintf(fplateau, "%d %d \n", nbjoueurs, tour_joueur);

    //Enregistrement des infomations de chaque joueur
    for (int i = 0; i < nbjoueurs; i++) {
        fprintf(fplateau, "%s %d %c %d %d %d\n",
            joueur[i].nom, joueur[i].etat, joueur[i].pion, joueur[i].barriere, joueur[i].couleur, joueur[i].coord_victoire);
    }
    fclose(fplateau);
}

//Chargement des barrieres sur le plateau
void chargement_barrieres(int *compteur_barriere, Barriere_plateau barriere[]) {
    FILE* fplateau = fopen("../barriere.txt", "r");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }
    //Lecture du nombre de barrieres
    fscanf(fplateau, "%d \n", compteur_barriere);

    //Lecture des coordonnées des barrieres
    for (int i = 0; i < *compteur_barriere; i++) {
        fscanf(fplateau, "%s %s %c \n",
            barriere[i].case1, barriere[i].case2, &barriere[i].cote);
    }
    fclose(fplateau);
}

//Chargement des coordonnées des joueurs
void chargement_coord_joueurs(Players joueur[], int* nbjoueurs) {
    FILE* fplateau = fopen("../coord_joueurs.txt", "r");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }
    //Lecture des informations et assignation des données à chaques joueurs
    for (int i = 0; i < *nbjoueurs; i++) {
        fscanf(fplateau, "%d %d\n",
        &joueur[i].coord_x, &joueur[i].coord_y);
    }
    fclose(fplateau);
}

//Chargement des informations des joueurs
void chargement_infos_joueurs(Players joueur[], int* nbjoueurs, int* tour_joueur) {
    FILE* fplateau = fopen("../infos_joueurs.txt", "r");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }
    //Lit la valeur enregistrée pour nbjoueur et l'assigne à la variable nbjoueur
    fscanf(fplateau, "%d %d\n", nbjoueurs, tour_joueur);

    //Lecture des informations et assignation des données à chaques joueurs
    for (int i = 0; i < *nbjoueurs; i++) {
        fscanf(fplateau, "%s %d %c %d %d %d \n",
        joueur[i].nom, &joueur[i].etat, &joueur[i].pion, &joueur[i].barriere, &joueur[i].couleur, &joueur[i].coord_victoire);
    }
    fclose(fplateau);
}

//Reinitialisation des barrieres
void reinitialisation_barriere(Barriere_plateau barriere[], int* compteur_barriere) {
    //En mettant compteur_barriere à 0, on ne peux plus parcourir le tableau
    *compteur_barriere = 0;
}

//Affichage du plateau
void affichage_plateau(int nb_joueurs, Players joueur[], int compteur_barriere, Barriere_plateau barriere[]) {
    int largeur_case = 4;
    int hauteur_case = 2;
    //Permet de réinitialiser les lignes (pour mettre le curseur à 0))
    system("cls");

    // Affichage des lettres en haut (A à I)
    gotoligcol(0, 1); // Départ avec un décalage
    for (char i = 'A'; i <= 'I'; i++) {
        printf("  %c ", i); // Alignement avec la largeur des cases
    }

    // Affichage des chiffres à gauche (1 à 9)
    for (int i = 0; i < TAILLE_TABLEAU; i++) {
        gotoligcol((i * hauteur_case) + hauteur_case, 0);
        printf("%d", i + 1);
    }

    //Affichage du plateau
    //TAILLE_TABLEAU * 2 car on a un espace entre chaques chiffres
    for (int i = 0; i <= TAILLE_TABLEAU*hauteur_case; i++) {
        gotoligcol(i+1, 1);
        //TAILLE_TABLEAU * 4 car on a 3 espaces entre chaques lettres (donc 4 places par cases)
        for (int j = 0; j <= TAILLE_TABLEAU*largeur_case; j++) {
            //Si on arrive sur une ligne entre les chiffres ou lettres, c'est une ligne pour barriere
            if ((i % hauteur_case == 0) || (j % largeur_case == 0)) {
                Color(0, 8);
                printf(" ");
            }
            else {
                Color(0, 15);
                printf(" ");
            }
        }
    }
    //Affichage des pions
    for (int i = 0; i < nb_joueurs; i++) {
        //Il semble que nous devons mettre "-1" pour la coord x sinon le pion est légèrement décalé
        gotoligcol(joueur[i].coord_y * hauteur_case, joueur[i].coord_x * largeur_case - 1);
        Color(joueur[i].couleur, 15);
        printf("%c", joueur[i].pion);

    }
    //Affichage des barrieres
    int decalage;
    for (int i = 0; i < compteur_barriere; i++) {
        decalage = 0;
        if (barriere[i].case1[0] == barriere[i].case2[0]) {
            if (barriere[i].cote == 'g')
                decalage--;
            else
                decalage++;
            gotoligcol((barriere[i].case1[1] - '1') * 2 + 2,
                      1 + (barriere[i].case1[0] - 'A' + 1) * 4 - 2 + 2*decalage);
            Color(0, 8);
            printf("|");
            Color(15, 0);
            gotoligcol((barriere[i].case2[1] - '1') * 2 + 2,
                       1 + (barriere[i].case2[0] - 'A' + 1) * 4 - 2 + 2*decalage);
            Color(0, 8);
            printf("|");
            Color(15, 0);
            //Remettre les couleurs d'origine
            Color(15, 0);
        } else {
            if (barriere[i].cote == 'h')
                decalage--;
            else
                decalage++;
            gotoligcol((barriere[i].case1[1] - '1') * 2 + 2 + decalage,
                      (barriere[i].case1[0] - 'A' + 1) * 4 - 2);
            Color(0, 8);
            printf("---");
            Color(15, 0);
            gotoligcol((barriere[i].case2[1] - '1') * 2 + 2 + decalage,
                       (barriere[i].case2[0] - 'A' + 1) * 4 - 2);
            Color(0, 8);
            printf("---");
            Color(15, 0);
        }
    }

    //Mettre le curseur en dessous du tableau affiché
    gotoligcol((TAILLE_TABLEAU + 1)*hauteur_case, 0);
}