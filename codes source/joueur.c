#include <stdio.h>
#include <string.h>
#include "../headers/joueur.h"

void initialisation_joueurs(Players joueur[4], int *nb_joueurs) {
    //déclaration des variables
    int i; //Pour les boucles

    //Choix du nombre de joueurs (blindé pour avoir 2 ou 4 comme valeur)
    do{
        printf("Entrez le nombre de joueurs (2 ou 4 joueurs):\n");
        scanf("%d", nb_joueurs);
    }while(*nb_joueurs != 2 && *nb_joueurs != 4);

    //Pseudo des joueurs
    for (i = 0; i < *nb_joueurs; i++) {
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

        //Choix de l'état du joueur
        do {
            printf("\n'%s' est une IA ou un humain ?\nRepondez par 1 (humain) ou 0 (IA)\n", joueur[i].nom);
            scanf(" %d", &joueur[i].etat);
        } while (joueur[i].etat != 0 && joueur[i].etat != 1);

        //Choix du pion
        printf("\nChoisissez un pion\n");
        scanf(" %c", &joueur[i].pion);

        //Initialisation du nombre de barrières
        joueur[i].barriere = (*nb_joueurs == 2)? 10 : 5;

        //Initialisation du score
        joueur[i].score = 0;

        //Initialisation de ses coordonnées en fonction du nombre de joueurs
        switch(i) {
            case 0:
                joueur[i].coord_x = 5;
                joueur[i].coord_y = 1; //On respecte la notation du plateau. La coordonnée minimale est 1.
            break;
            case 1:
                joueur[i].coord_x = 5;
                joueur[i].coord_y = 9; //La coordonnée maximale du plateau est 9.
                break;
            case 2:
                joueur[i].coord_x = 1;
                joueur[i].coord_y = 5;
            break;
            case 3:
                joueur[i].coord_x = 9;
                joueur[i].coord_y = 5;
            break;
            default:
                printf("Erreur veuillez relancer le programme");
            break;
        }
    }
}