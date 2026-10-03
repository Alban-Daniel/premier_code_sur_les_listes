#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog_liste.h"

    /// fonction d'Initialisation de la liste

    void initialisation(T_Liste* liste){

        liste->debut = NULL;
        liste->fin = NULL;
        liste->taille = 0;

    }

    /// fonction d'insertion dans une liste vide

    int ins_dans_liste_vide(T_Liste* liste, char *nouv_donnee){

        int y=0;
        Element_Liste* nouveau;

        nouveau = (Element_Liste*)malloc(sizeof(Element_Liste));
        if(nouveau == NULL){
           y=-1;
        }

        nouveau->donnee = (char*)malloc(51);
        if(nouveau->donnee == NULL){
            y=1;
        }
        strcpy(nouveau->donnee, nouv_donnee);
        nouveau->suivant = NULL;
        liste->debut = nouveau;
        liste->fin = nouveau;
        liste->taille++;

        return y;

        }


/// FONCTION POUR INSERER AU DEBUT DE LA LISTE

int ins_debut_liste(T_Liste* liste, char *nouv_donnee){

   int y=0;
    Element_Liste* nouveau;

    nouveau = (Element_Liste*)malloc(sizeof(Element_Liste));

    if(nouveau == NULL){
        y=-1;
    }

    nouveau->donnee = (char*)malloc(51);

    if(nouveau->donnee == NULL){
        y=1;
    }
    strcpy(nouveau->donnee, nouv_donnee);
    nouveau->suivant = liste->debut;
    liste->debut = nouveau;
    liste->taille++;

    return y;


}


/// FONCTION POUR INSERER A LA FIN DE LA LISTE

int ins_fin_liste(T_Liste* liste, char* donnee){
    int y=0;
    Element_Liste*nouveau = (Element_Liste*)malloc(sizeof(Element_Liste));
    if(nouveau==NULL){
        y=-1;
    }
    nouveau->donnee = (char*)malloc(51);
    if(nouveau->donnee==NULL){
        y=1;
    }
    strcpy(nouveau->donnee, donnee);
    liste->fin->suivant=nouveau;
    liste->fin=nouveau;
    nouveau->suivant=NULL;
    liste->taille++;
    return y;
}

/// FONCTION POUR INSERER APRES UNE POSITION DONNEE

int ins_apres_position(T_Liste* liste, char* donnee, int pos){
    Element_Liste* courant = (Element_Liste*)malloc(sizeof(Element_Liste));
    int y=0;
    Element_Liste* nouveau = (Element_Liste*)malloc(sizeof(Element_Liste));
    if (nouveau == NULL){
        y=-1;
    }
    nouveau->donnee = (char*)malloc(51);
    if(nouveau->donnee == NULL){
        y=1;
    }
    strcpy(nouveau->donnee, donnee);
    courant=liste->debut;
    for (int i=1; i<pos; ++i){
        courant = courant->suivant;
    }
    nouveau->suivant=courant->suivant;
    courant->suivant=nouveau;
    liste->taille++;
    return y;
}


/// FONCTION POUR SUPPRIMER AU DEBUT DE LA LISTE

int supp_debut (T_Liste * liste){
    int y=0;
  if (liste->taille == 0){
        printf("\nLa liste est vide");
    y = -1;
  }
  Element_Liste *supp_element;
  supp_element = liste->debut;
  liste->debut = liste->debut->suivant;
  if (liste->taille == 1){
    liste->fin = NULL;
  }
    free (supp_element->donnee);
    free (supp_element);
    liste->taille--;
  return y;
}

///  FONCTION POUR SUPPRIMER APRES UNE POSITION DONNEE

int supp_dans_liste (T_Liste * liste, int pos){
    int y = 0;
    if(liste->taille == 0){
        printf("\nLa liste est vide");
    }
   if (liste->taille <= 1 || pos < 1 || pos >= liste->taille){
    y = -1;
   }
   int i;
   Element_Liste *courant;
   Element_Liste *supp_element;
   courant = liste->debut;
   for (i = 1; i < pos; ++i){
      courant = courant->suivant;
   }
   supp_element = courant->suivant;
   courant->suivant = courant->suivant->suivant;
   if(courant->suivant == NULL){
     liste->fin = courant;
   }
   free (supp_element->donnee);
   free (supp_element);
   liste->taille--;
   return y;
}

/// FONCTION POUR AFFICHER LA LISTE


void afficher_liste(T_Liste* liste){
    Element_Liste* courant = (Element_Liste*)malloc(sizeof(Element_Liste));
    if (liste->taille == 0){
        printf("\nLa liste est vide");
    }
    else{
        printf("\nDebut\t\t\tFin\n");
        printf("%s\t\t%s\n", liste->debut->donnee, liste->fin->donnee);

        printf("\n\t\tLES ELEMENTS DE LA LISTE\n");
        courant = liste->debut;
        while(courant != NULL){
            printf("\nPointeur\t\tElement\t\tSuivant");
            printf("\n%p\t%s\t%p",courant, courant->donnee, courant->suivant);
            courant = courant->suivant;
            printf("\n");
        }

    }
}

