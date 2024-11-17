#include <stdio.h>
#include <string.h>
#include "../headers/joueur.h"
#include "../headers/menu.h"

void initialisation_joueurs(int *nbjoueurs, Joueur joueur[]) {
    //Choix du nombre de joueurs
    do{
        printf("Entrez le nombre de joueurs (2 ou 4 joueurs:\n");
        scanf("%d", &nbjoueurs);
    }while(*nbjoueurs != 2 && *nbjoueurs != 4);
    //Boucle pour remplir les informations des joueurs indiqué
    for (int i = 0; i<*nbjoueurs; i++) {
        //Pseudo de 20 caratère maximum
        do {
            printf("Joueur %d, entrez votre pseudo(20 caractères au maximum):\n", i+1);
            scanf("%s", joueur[i].nom);
        } while(strlen(joueur[i].nom) > 20);
        //Choix de l'état du joueur (IA ou humain)
        do {
            printf("Choisissez si le joueur %d est un humain(1) ou un ordinateur(0)", i+1);
            scanf("%d", joueur[i].etat);
        } while (joueur[i].etat != 0 && joueur[i].etat != 1);
    }
}