#include <stdio.h>
#include "../headers/joueur.h"
#include "../headers/plateau.h"

void sauvegarde_plateau(Players joueur[], int nbjoueurs) {
    FILE* fplateau = fopen("plateau.txt", "w");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }

    //Enregistrement du nombre de joueurs
    fprintf(fplateau, "%d\n", nbjoueurs);

    //Enregistrement des infomations de chaque joueur
    for (int i = 0; i < nbjoueurs; i++)
        fprintf(fplateau, "%s %d %c %d %d %d %d \n",
            joueur[i].nom, joueur[i].etat, joueur[i].pion, joueur[i].barriere, joueur[i].coord_x, joueur[i].coord_y, joueur[i].score);
    fclose(fplateau);
}

void chargement_plateau(Players *joueur[], int* nbjoueurs) {
    FILE* fplateau = fopen("plateau.txt", "r");
    if (fplateau == NULL) {
        printf("Erreur\n");
        return;
    }

    //Lit la valeur enregistrée pour nbjoueur et l'assigne à la variable nbjoueur
    fscanf(fplateau, "%d\n", nbjoueurs);

    //Lecture des informations et assignation des données à chaques joueurs
    for (int i = 0; i < *nbjoueurs; i++) {
        fscanf(fplateau, "%s %d %c %d %d %d %d \n",
        joueur[i]->nom, joueur[i]->etat, joueur[i]->pion, joueur[i]->barriere, joueur[i]->coord_x, joueur[i]->coord_y, joueur[i]->score);
    }
        fclose(fplateau);
}