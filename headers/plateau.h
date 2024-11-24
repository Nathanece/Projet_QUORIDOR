#ifndef PLATEAU_H
#define PLATEAU_H

typedef struct {
    char case1[3]; //Format A1, B6, ...
    char case2[3]; //Format A1, B6 ...
    char cote; //'g' pour gauche, 'h' pour haut, ...
}Barriere_plateau;

//Sauvegarde des différentes infos
void sauvegarde_barrieres(int compteur_barriere, Barriere_plateau barriere[]);
void sauvegarde_coord_joueurs(Players joueur[], int nbjoueurs);
void sauvegarde_info_joueurs(Players joueur[], int nbjoueurs, int tour_joueur);

//Chargement des différentes infos
void chargement_barrieres(int *compteur_barriere, Barriere_plateau barriere[]);
void chargement_coord_joueurs(Players joueur[], int* nbjoueurs);
void chargement_infos_joueurs(Players joueur[], int* nbjoueurs, int* tour_joueur);

//Affichage du plateau de jeu
void affichage_plateau(int nb_joueurs, Players joueur[], int compteur_barriere, Barriere_plateau barriere[]);
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol(int lig, int col);

#endif //PLATEAU_H