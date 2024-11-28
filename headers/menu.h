#ifndef MENU_H
#define MENU_H
#include "joueur.h"
#include "plateau.h"

//Menus affichés aux joueurs (soit avant une partie, soit pour choisir son action)
void menu(int *choix);
int menu_action(int tour_joueur, Players joueur[]);
//Tirage au sort pour savoir quel joueur commence et changement de tour pour la suite
int tirage_au_sort(int nb_joueurs);
void changement_tour(int* tour_joueur, int nb_joueurs);
//Fiche d'aide pour savoir comment joueur
void fiche_aide();
//Actions réalisée à la suite d'un choix
void deplacer_pion(int tour_joueur, Players joueur[], int nb_joueurs, int compteur_barrieres, Barriere_plateau barrieres[]);
void poser_barriere(Barriere_plateau barrieres[20], Players joueur[], int *compteur_barriere, int tour_joueur);
//Affichage des scores (choix dans le menu principal)
void afficher_scores(Players joueur[], int nb_joueurs);
//Fermer le jeu si le joueur décide d'arreter
int quitter_jeu();

#endif //MENU_H