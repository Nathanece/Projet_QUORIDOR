#ifndef PLATEAU_H
#define PLATEAU_H

void sauvegarde_plateau(Players joueur[], int nbjoueurs, int tour_joueur);
void chargement_plateau(Players joueur[], int* nbjoueurs, int* tour_joueur);
void affichage_plateau(int nb_joueurs, Players joueur[]);
void Color(int couleurDuTexte,int couleurDeFond);

#endif //PLATEAU_H