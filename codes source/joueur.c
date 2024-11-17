#include <stdio.h>
#include <string.h>
#include "../headers/joueur.h"

void initialisation_joueurs() {
    //déclaration des variables
    Players joueur[4]; //La structure de chacun des joueurs sera dans ce tableau
    int nb_joueurs;
    int i; //Pour les boucles

    //Choix du nombre de joueurs (blindé pour avoir 2 ou 4 comme valeur)
    do{
        printf("Entrez le nombre de joueurs (2 ou 4 joueurs):\n");
        scanf("%d", &nb_joueurs);
    }while(nb_joueurs != 2 && nb_joueurs != 4);

    //Pseudo des joueurs
    for (i = 0; i<nb_joueurs; i++) {
        int identique = 0;
        //Pseudo de 20 caratère maximum
        do {
            identique = 0;
            printf("\nJoueur %d, entrez votre pseudo(20 caracteres au maximum):\n", i+1);
            scanf("%s", joueur[i].nom);
            //Verification si un pseudo est identique
            for (int j = 0; j < i; j++) {
                (strcmp(joueur[i].nom, joueur[j].nom) == 0)? identique++ : 0;
            }
            if (identique)
                printf("Ce pseudo est deja prit");
        } while(strlen(joueur[i].nom) > 20 || identique);
    }

    //Choix de l'état du joueur
    for (i = 0; i<nb_joueurs; i++) {
        do {
            printf("\n'%s' est une IA ou un humain ?\nRepondez par 1 (humain) ou 0 (IA)\n", joueur[i].nom);
            scanf(" %d", &joueur[i].etat);
        } while (joueur[i].etat != 0 && joueur[i].etat != 1);

        //Initialisation du nombre de barrières
        joueur[i].barriere = (nb_joueurs == 2)? 10 : 5;
    }
}