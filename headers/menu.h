#ifndef MENU_H
#define MENU_H
#include "joueur.h"
#include "plateau.h"

int menu();
int tirage_au_sort(int nb_joueurs);
void deplacer_pion(int tour_joueur, Players joueur[]);
void menu_action(int tour_joueur, Players joueur[], int nb_joueurs, Barriere_plateau barrieres[], int *compteur_barriere);
void fiche_aide();

#endif //MENU_H