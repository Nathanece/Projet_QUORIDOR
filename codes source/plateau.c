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

void sauvegarde_plateau(Players joueur[], int nbjoueurs) {
    FILE* fplateau = fopen("../plateau.txt", "w");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }

    //Enregistrement du nombre de joueurs
    fprintf(fplateau, "%d\n", nbjoueurs);

    //Enregistrement des infomations de chaque joueur
    for (int i = 0; i < nbjoueurs; i++) {
        fprintf(fplateau, "%s %d %c %d %d %d %d \n",
            joueur[i].nom, joueur[i].etat, joueur[i].pion, joueur[i].barriere, joueur[i].coord_x, joueur[i].coord_y, joueur[i].score);
    }
    fclose(fplateau);
}

void chargement_plateau(Players joueur[], int* nbjoueurs) {
    FILE* fplateau = fopen("../plateau.txt", "r");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }

    //Lit la valeur enregistrée pour nbjoueur et l'assigne à la variable nbjoueur
    fscanf(fplateau, "%d\n", nbjoueurs);

    //Lecture des informations et assignation des données à chaques joueurs
    for (int i = 0; i < *nbjoueurs; i++) {
        fscanf(fplateau, "%s %d %c %d %d %d %d \n",
        joueur[i].nom, &joueur[i].etat, &joueur[i].pion, &joueur[i].barriere, &joueur[i].coord_x, &joueur[i].coord_y, &joueur[i].score);
    }
        fclose(fplateau);
}


//Affichage du plateau
void affichage_plateau() {
    //Permet de réinitialiser les lignes (pour mettre le curseur à 0))
    system("cls");

    // Affichage des lettres en haut (A à I)
    gotoligcol(0, 1); // Départ avec un décalage
    for (char i = 'A'; i <= 'I'; i++) {
        printf("  %c ", i); // Alignement avec la largeur des cases
    }

    // Affichage des chiffres à gauche (1 à 9)
    for (int i = 0; i < TAILLE_TABLEAU; i++) {
        gotoligcol((i * 2) + 2, 0);
        printf("%d", i + 1);
    }

    //Affichage du plateau
    //TAILLE_TABLEAU * 2 car on a un espace entre chaques chiffres
    for (int i = 0; i <= TAILLE_TABLEAU*2; i++) {
        gotoligcol(i+1, 1);
        //TAILLE_TABLEAU * 4 car on a 3 espaces entre chaques lettres (donc 4 places par cases)
        for (int j = 0; j <= TAILLE_TABLEAU*4; j++) {
            //Si on arrive sur une ligne entre les chiffres ou lettres, c'est une ligne pour barriere
            if ((i%2 == 0) || (j%4 == 0)) {
                Color(0, 8);
                printf(" ");
            }
            else {
                Color(0, 15);
                printf(" ");
            }
        }
    }
    //Remettre les couleurs d'origine
    Color(15, 0);
}