#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct Element_Liste {

        char *donnee;
        struct Element_Liste* suivant;

}Element_Liste;

typedef struct T_Liste {

        Element_Liste* debut;
        Element_Liste* fin;
        int taille;

}T_Liste;

/// Initialisation de la liste
void initialisation(T_Liste* liste);

/// Insertion au debut de la liste
int ins_debut_liste(T_Liste* liste, char *nouv_donnee);

/// Insertion dans une liste vide
int ins_dans_liste_vide(T_Liste* liste, char *nouv_donnee);

/// Insertion à la fin de la liste
int ins_fin_liste(T_Liste* liste, char* donnee);

/// Insertion apres une position donnee
int ins_apres_position(T_Liste* liste, char* donnee, int pos);

/// Supprimer au début de la liste
int supp_debut (T_Liste * liste);

/// Supprimer apres une position donnee
int supp_dans_liste (T_Liste * liste, int pos);

/// Affichage de la liste
void afficher_liste(T_Liste* liste);

#endif

