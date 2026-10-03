#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "prog_liste.h"



int main()
{
    setlocale(LC_ALL, "");

    T_Liste* Liste2 = (T_Liste*)malloc(sizeof(T_Liste));
    initialisation(Liste2);

    printf("\n\t\tTRAVAIL SUR UNE NOUVELLE LISTE");
    printf("\n\t\tVOUS AVEZ LE MENU DEVANT VOUS, FAITES VOTRE CHOIX");
                              char *nom3 = (char*)malloc(51);
                              if(nom3 == NULL){
                                  printf("\nAllocation echouweee pour l'element à inserer eventuellement");
                              }
    int choix = -1;
    while (choix != 4)

    {
      printf("\nSaisir:\n 1- Si vous voulez ajouter un element à la liste\n 2- Si vous voulez afficher la liste\n 3- Si vous voulez supprimer un élément de la liste\n 4- Si vous voulez quitter");

      printf("\nEntrez votre choix\n");
      scanf("%d", &choix);
      switch(choix)
         {
            case 1:
               /// Pour ajouter un nouveau élément à la liste
                 /// Insertion dans une liste vide
                 if(Liste2->taille==0){
                    printf("\nEntrer le nom\n");
                    scanf("%s", nom3);
                    int t = ins_dans_liste_vide(Liste2,nom3);
                    printf("\n%d", t);
                 }
                 else{
                     printf("\nSaisir:\n 1- Si vous voulez inserer au debut de la liste\n 2- Si vous voulez inserer à la fin de la liste\n 3- Si vous voulez insérer apres une position donnée\n 4- Si vous voulez supprimer un élément\n");
                     int choix_ins = -1;
                     printf("\nEntrez votre choix\n");
                     scanf("%d", &choix_ins);

                    switch (choix_ins)
                      {

                         case 1:
                               /// Insertion au debut de la liste

                            printf("\nEntrer le nom\n");
                            scanf("%s", nom3);
                            int t = ins_debut_liste(Liste2,nom3);
                            printf("%d", t);
                            break;

                         case 2:
                            /// Insertion à la fin de la liste
                            printf("\nEntrer le nom\n");
                            scanf("%s", nom3);
                            t = ins_fin_liste(Liste2,nom3);
                            printf("%d", t);
                            break;

                         case 3:
                            /// Insertion apres une position donnee
                            printf("\nEntrer le nom\n");
                            scanf("%s", nom3);
                            int pos;
                            printf("\nEntrer la position apres laquelle il sera place\n");
                            scanf("%d",&pos);
                            if(pos!=Liste2->taille){
                                while(pos>Liste2->taille){
                                printf("\n\t!!!! Erreur de position !!!! \tLa taille de la liste est : %d", Liste2->taille);
                                printf("\nEntrer la position apres laquelle il sera place\n");
                                scanf("%d",&pos);
                             }

                               t = ins_apres_position(Liste2, nom3, pos);
                               printf("\n%d", t);
                            }
                            else{
                                t = ins_fin_liste(Liste2, nom3);
                                printf("\n%d", t);
                            }
                            break;

                         default:
                            printf("\n Il n'y a pas ce choix dans le menu");

                     }

                 }
                 break;

             case 2:
                 /// Pour afficher la liste
                 afficher_liste(Liste2);
                 break;

             case 3:
                /// Pour supprmer un élément de la liste
                printf("\nSaisir:\n 1- Si vous voulez supprimer au début\n 2- Si vous voulez supprimer apres une position donnée\n");
                int choix_sup = -1;
                scanf("%d", &choix_sup);
                switch (choix_sup)
                {
                   case 1:
                     printf("Suppression au début de la liste");
                     int t = supp_debut(Liste2);
                     printf("\n%d", t);
                     break;

                   case 2:
                       printf("\nEntrer la position apres laquelle vous voulez supprimer");
                       int pos;
                       scanf("%d", &pos);
                       t = supp_dans_liste(Liste2, pos);
                       printf("\n%d", t);
                       break;
                }

                break;


             case 4:
                /// Pour quitter le menu
                free(nom3);
                free(Liste2);
                printf("Ok, au revoir");
                break;

             default:
                 printf("\n Il n'y a pas ce choix dans le menu");

        }
    }

    return 0;

}
