#ifndef MENU_H
#define MENU_H
#include "joueur.h"
#include "plateau.h"

int menu();
int tirage_au_sort(int nb_joueurs);
void deplacer_pion(int tour_joueur, Players joueur[],int compteur_barrieres, Barriere_plateau barrieres[]);
int menu_action(int tour_joueur, Players joueur[]);
void fiche_aide();
void poser_barriere(Barriere_plateau barrieres[20], Players joueur[], int *compteur_barriere, int tour_joueur);
void changement_tour(int* tour_joueur, int nb_joueurs);

#endif //MENU_H