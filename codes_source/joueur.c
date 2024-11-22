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
                joueur[i].couleur  = 1; //Couleur bleu
            break;
            case 1:
                joueur[i].coord_x = 5;
                joueur[i].coord_y = 9; //La coordonnée maximale du plateau est 9.
                joueur[i].couleur  = 4; //Couleur rouge
                break;
            case 2:
                joueur[i].coord_x = 1;
                joueur[i].coord_y = 5;
                joueur[i].couleur  = 5; //Couleu violet
            break;
            case 3:
                joueur[i].coord_x = 9;
                joueur[i].coord_y = 5;
                joueur[i].couleur  = 2; //Couleur vert
            break;
            default:
                printf("Erreur veuillez relancer le programme");
            break;
        }
    }
}


void sauvegarder_scores(Players joueur[], int nb_joueurs) {
    // Ouverture du fichier en mode ajout
    FILE *fichier = fopen("../scores.txt", "a+");

    // Vérification si le fichier est correctement ouvert
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier des scores.\n");
        return;
    }

    // Écriture des scores de tous les joueurs dans le fichier
    for (int i = 0; i < nb_joueurs; i++) {
        fprintf(fichier, "%s %d\n", joueur[i].nom, joueur[i].score);
    }

    // Fermeture du fichier pour libérer les ressources
    fclose(fichier);
    printf("Scores sauvegardés avec succès.\n");
}



void charger_scores(Players joueur[], int nb_joueurs) {
    // Ouverture du fichier en mode lecture
    FILE *fichier = fopen("../scores.txt", "r");

    // Vérification si le fichier est accessible
    if (fichier == NULL) {
        printf("Aucun fichier de scores trouvé. Les scores démarrent à 0.\n");
        return;
    }

    // Variables temporaires pour stocker les données lues
    char nom_temp[pseudo];
    int score_temp;

    // Lecture ligne par ligne des noms et scores du fichier
    while (fscanf(fichier, "%s %d\n", nom_temp, &score_temp) != EOF) {
        for (int i = 0; i < nb_joueurs; i++) {
            if (strcmp(joueur[i].nom, nom_temp) == 0) {
                joueur[i].score = score_temp;
                break;
            }
        }
    }

    // Fermeture du fichier après la lecture
    fclose(fichier);
    printf("Scores chargés avec succès.\n");
}