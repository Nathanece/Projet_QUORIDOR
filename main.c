#include "headers/joueur.h"
#include "headers/menu.h"
#include "headers/plateau.h"


int main() {
    //Initialisation des variables
    int nb_joueurs = 0;
    int tour_joueur = 0;
    int compteur_barrieres = 0;
    Players joueur[4];//La structure de chacun des joueurs sera dans ce tableau
    Barriere_plateau barrieres[20];

    //Appel du menu principal
    int choix = menu();
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
            break;
        default:
            break;
    }
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
                deplacer_pion(tour_joueur, joueur);
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