#ifndef JOUEUR_H
#define JOUEUR_H

#define pseudo 21 //20 cases utiles et une de plus pour le \0
typedef struct {
    char nom[pseudo]; //pseudo du joueur
    int etat; //0 pour joueur, 1 pour IA
    char pion; //Caractère pouvant être semis graphique
    int barriere; //Sa valeur initiale dépend du nombre de joueurs
    int coord_x, coord_y;
    int score;
    int couleur;
} Players; //Structure des joueurs


void initialisation_joueurs(Players joueur[4], int *nb_joueurs);

#endif //JOUEUR_H
