#include <stdio.h>
#include <windows.h>

#include "headers/joueur.h"
#include "headers/menu.h"
#include "headers/plateau.h"


int main() {
    //DECLARATION DES VARIABLES
    int retour = 0; //Pour revenir au menu principal
    int choix = 0; //Choix dans le menu principal
    int nb_joueurs = 0; //Nombre de joueurs
    int tour_joueur = 0;//Le tour actuel du joueur (pour tourner)
    int compteur_barrieres = 0;//Le nombre de barrieres posées
    Players joueur[4];//La structure de chacun des joueurs sera dans ce tableau
    Barriere_plateau barrieres[20];//La structure des barrieres
    int fin = 0; //Verifie si la partie est finie
    int quitter = 0; //Vérifie si l'utilisateur veut sauvegarder et quitter la partie
    int continuer_partie = 0; //Permet de continuer à jouer après la fin d'une manche

    do {
        //Appel du menu principal
        do{
            //Initialisation de retour pour éviter d'avoir une boucle infinie si retour = 1 (avec un autre choix)
            retour = 0;
            //Réinitialise l'écran (plus rien n'est affiché)
            system("cls");
            menu(&choix);
            //Les fonctions à appeler en fonction du choix de l'utilisateur
            switch(choix) {
                case 1:
                    creation_joueurs(joueur, &nb_joueurs);
                tour_joueur = tirage_au_sort(nb_joueurs);
                sauvegarde_info_joueurs(joueur, nb_joueurs, tour_joueur);
                break;
                case 2:
                chargement_coord_joueurs(joueur, &nb_joueurs);
                chargement_barrieres(&compteur_barrieres, barrieres);
                charger_scores(joueur, nb_joueurs);
                chargement_infos_joueurs(joueur, &nb_joueurs, &tour_joueur);
                break;
                case 3:
                    system("cls");
                    fiche_aide();
                //Demande pour quitter ou non le jeu
                retour = quitter_jeu();
                break;
                case 4:
                    chargement_infos_joueurs(joueur, &nb_joueurs, &tour_joueur);
                    charger_scores(joueur, nb_joueurs);
                    system("cls");
                    afficher_scores(joueur, nb_joueurs);
                //Demande pour quitter ou non le jeu
                retour = quitter_jeu();
                break;
                case 5:
                    retour = 0;
                break;
                default:
                    break;
            }
        } while (retour);
        //Initalise fin à 0 avant de commencer à jouer
        if (choix == 1 || choix == 2) {
            do{
                continuer_partie = 0;
                do {
                    fin = 0;
                    quitter = 0;
                    //Sauvegarde des informations du jeu (positions, joueurs, ...)
                    sauvegarde_coord_joueurs(joueur, nb_joueurs);
                    sauvegarde_barrieres(compteur_barrieres, barrieres);

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
                        case 4:
                            sauvegarde_info_joueurs(joueur, nb_joueurs, tour_joueur);
                            sauvegarde_coord_joueurs(joueur, nb_joueurs);
                            sauvegarde_barrieres(compteur_barrieres, barrieres);
                            sauvegarder_scores(joueur, nb_joueurs);
                        quitter = 1;
                    }
                    changement_tour(&tour_joueur, nb_joueurs);
                    verification_fin(joueur, nb_joueurs, &fin);
                } while (fin == 0 && quitter == 0);
                if (fin) {
                    Sleep(3000);
                    system("cls");
                    //Reinitialisation et sauvegarde des coordonnées des joueurs pour une prochaine partie
                    reinitialisation_coord_joueurs(joueur, nb_joueurs);
                    sauvegarde_coord_joueurs(joueur, nb_joueurs);

                    //Reinitialisation et sauvegarde des barrieres
                    reinitialisation_barriere(barrieres, &compteur_barrieres);
                    sauvegarde_barrieres(compteur_barrieres, barrieres);

                    sauvegarder_scores(joueur, nb_joueurs);
                    printf("Voulez vous continuer ? (1 : oui, 0 : non)\n");
                    scanf(" %d", &continuer_partie);
                }
                else
                    continuer_partie = 0;
            } while (continuer_partie);
            retour = 1;
        }
    } while (retour);
    return 0;
}