#include <stdio.h>
#include "../headers/joueur.h"
#include "../headers/menu.h"

void menu_initialisation() {
    do{
        printf("Entrez le nombre de joueurs (2 ou 4 joueurs:\n");
        scanf("%d", &nbjoueurs);
    }while(nbjoueurs != 2 && nbjoueurs != 4);
    if (nbjoueurs >= 2)
        sJoueur joueur1, joueur2;
    if (nbjoueurs == 4)
        sJoueur joueur3, joueur4;
}

void menu_action() {
    
}