#include <stdio.h>
#include <windows.h>

#include "headers/joueur.h"
#include "headers/menu.h"
#include "headers/plateau.h"


int main() {
    //Initialisation des variables
    int retour = 0; //Pour revenir au menu principal
    int choix = 0; //Choix dans le menu principal
    int nb_joueurs = 0; //Nombre de joueurs
    int tour_joueur = 0;//Le tour actuel du joueur (pour tourner)
    int compteur_barrieres = 0;//Le nombre de barrieres posées
    Players joueur[4];//La structure de chacun des joueurs sera dans ce tableau
    Barriere_plateau barrieres[20];//La structure des barrieres

    //Appel du menu principal
    do{
        system("cls");
        menu(&choix);
        //Les fonctions à appeler en fonction du choix de l'utilisateur
        switch(choix) {
            case 1:
                initialisation_joueurs(joueur, &nb_joueurs);
            tour_joueur = tirage_au_sort(nb_joueurs);
            break;
            case 2:
                chargement_plateau(joueur, &nb_joueurs, &tour_joueur, &compteur_barrieres, barrieres);
            break;
            case 3:
                fiche_aide();
            //Demande pour quitter ou non le jeu
            retour = quitter_jeu();
            break;
            case 4:
                afficher_scores();
            //Demande pour quitter ou non le jeu
            retour = quitter_jeu();
            default:
                break;
        }
    } while (retour);
    if (choix == 1 || choix == 2) {
        do {
            //Sauvegarde des informations du jeu (positions, joueurs, ...)
            sauvegarde_plateau(joueur, nb_joueurs, tour_joueur, compteur_barrieres, barrieres);

            //Affichage du tableau
            affichage_plateau(nb_joueurs, joueur, compteur_barrieres, barrieres);
            //Appel du menu d'action
            int action = menu_action(tour_joueur, joueur);
            //Actions à réaliser en fonction du choix retourné
            switch(action) {
                //Cas où le joueur veut déplacer son pion
                case 1:
                    deplacer_pion(tour_joueur, joueur, nb_joueurs, compteur_barrieres, barrieres);
                break;
                //Cas où le joueur veut placer une barriere
                case 2:
                    poser_barriere(barrieres, joueur, &compteur_barrieres, tour_joueur);
                break;
                //Cas où le joueur veut sauter son tour
                case 3:
                    break;
            }
            changement_tour(&tour_joueur, nb_joueurs);
        } while (1);
    }
}