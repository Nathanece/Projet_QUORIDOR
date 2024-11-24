#ifndef MENU_H
#define MENU_H
#include "joueur.h"
#include "plateau.h"

void menu(int *choix);
int tirage_au_sort(int nb_joueurs);
void deplacer_pion(int tour_joueur, Players joueur[], int nb_joueurs, int compteur_barrieres, Barriere_plateau barrieres[]);
int menu_action(int tour_joueur, Players joueur[]);
void fiche_aide();
void poser_barriere(Barriere_plateau barrieres[20], Players joueur[], int *compteur_barriere, int tour_joueur);
void changement_tour(int* tour_joueur, int nb_joueurs);
void afficher_scores();
void fiche_aide();
int quitter_jeu();

#endif //MENU_H