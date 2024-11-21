#ifndef PLATEAU_H
#define PLATEAU_H

typedef struct {
    char case1[2]; //Format A1, B6, ...
    char case2[2]; //Format A1, B6 ...
    char cote; //'g' pour gauche, 'h' pour haut, ...
}Barriere_plateau;

void sauvegarde_plateau(Players joueur[], int nbjoueurs, int tour_joueur, int compteur_barriere, Barriere_plateau barriere[]);
void chargement_plateau(Players joueur[], int* nbjoueurs, int* tour_joueur, int *compteur_barriere, Barriere_plateau barriere[]);
void affichage_plateau(int nb_joueurs, Players joueur[], int compteur_barriere, Barriere_plateau barriere[]);
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol(int lig, int col);

#endif //PLATEAU_H