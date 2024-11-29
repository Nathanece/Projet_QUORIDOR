// Fonction pour afficher l'aide générale
void afficher_aide_generale() {
    printf("\n=== AIDE QUORIDOR ===\n");
    printf("1. Chaque joueur commence à un côté opposé du plateau.\n");
    printf("2. L'objectif est d'atteindre le côté opposé du plateau avant l'adversaire.\n");
    printf("3. Le joueur peut déplacer son pion, ou poser un mur à son tour.\n");
    printf("4. Les murs bloquent le chemin.\n");
    printf("5. Le jeu se joue à tour de rôle.\n");
}

// Fonction pour expliquer les déplacements possibles
void afficher_deplacements() {
    printf("\n=== DÉPLACEMENTS ===\n");
    printf("1. Le pion peut prendre quatre directions : haut, bas, gauche, ou droite.\n");
    printf("2. Si un mur bloque votre chemin, le joueur choisit une autre direction.\n");
    printf("3. Un joueur peut faire sauter son pion sur un le pion de son adversaire .\n");
}

// Fonction pour expliquer le placement des murs
void afficher_murs() {
    printf("\n=== PLACEMENT DES MURS ===\n");
    printf("1. Chaque joueur commence la partie avec 10 murs.\n");
    printf("3. Un mur bloque le chemin mais ne peut pas bloquer entièrement un joueur.\n");
    printf("4. Une fois placé, un mur ne peut pas être déplacé.\n");
}

// Fonction pour expliquer les conditions de victoire
void afficher_conditions_victoire() {
    printf("\n=== CONDITIONS DE VICTOIRE ===\n");
    printf("1. Le premier joueur à atteindre le côté opposé du plateau gagne la partie.\n");
}
