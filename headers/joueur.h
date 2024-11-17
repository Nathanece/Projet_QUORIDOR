#ifndef JOUEUR1_H
#define JOUEUR1_H

#define coordonnees 2
#define pseudo 21 //20 cases utiles et une de plus pour le \0
typedef struct {
    char nom[pseudo]; //pseudo du joueur
    int coordonnee_x, coordonnee_y;
    int stock_barriere; //Sa valeur initiale dépend du nombre de joueurs
    int score;
    int etat; //0 pour joueur, 1 pour IA
} Joueur; //Structure des joueurs

Joueur joueur[4]; //Peux contenir soit les 2 joueurs, soit les 4

#endif //JOUEUR1_H
