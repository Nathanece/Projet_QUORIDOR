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
    int coord_victoire;
} Players; //Structures des joueurs

//Fonction d'enregistrement des infos des joueurs pour une nouvelle partie
void creation_joueurs(Players joueur[4], int *nb_joueurs);
//Reinitialisation des informations (coordonnées et barrieres) au debut de chaques nouvelles manches
void reinitialisation_coord_joueurs(Players joueur[], int nb_joueurs);
//Sauvegarde du score après une manche terminée
void sauvegarder_scores(Players joueur[], int nb_joueurs);
//Chargement des scores lors de la reprise d'une ancienne partie
void charger_scores(Players joueur[], int nb_joueurs);
//Augmentation du score lors de la victoire d'un joueur
void mettre_a_jour_scores(Players joueur[], int gagnant);
//Verification de la fin de la partie (lorsqu'un joueur à atteint le bord opposé)
void verification_fin(Players joueur[], int nb_joueur, int* fin);


#endif //JOUEUR_H
