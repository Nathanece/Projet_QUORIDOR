#ifndef JOUEUR1_H
#define JOUEUR1_H

#define coordonnees 2
#define pseudo 20
typedef struct {
    char nomJ1[pseudo]; //pseudo du joueur
    int coordonneesJ1[coordonnees]; //(format x, y pour coordonnées)
    int stock_barriere;
    int scoreJ1;
    int etat; //pour savoir si c'est un joueur(on mettra 0) ou un ordinateur(1).
} sJoueur;
//Cette structure est identique pour chaques joueurs
void intialisation();
/*La fonction initialisation propose à l'utilisateur de choisir le nombre
 *de joueurs et si ces joueurs sont des ordinateurs ou des personnes */

#endif //JOUEUR1_H
