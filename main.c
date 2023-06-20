#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
    FILE* catalogue = NULL;
    FILE* fichier = NULL;
    int choix, choix2, retour=0, retour2=0;
    char* resultat = NULL;
    char* chaine = NULL;
    if((chaine = (char*)calloc(21, sizeof(char))) == NULL)
    {
        printf("Impossible d'allouer la variable chaine\n");
        exit(EXIT_FAILURE);
    }
 
    do
    {
        if (retour==0)
            printf("\n");
             
        retour = 0;
        printf("-------------- Menu --------------\n\n\n\n\n");
        printf("1) Ajouter un article\n\n\n\n");
        printf("2) Consulter la liste des articles\n\n\n\n");
        printf("3) Rechercher un article\n\n\n\n");
        printf("0) Quitter\n\n");
        printf("\n\n\n\n --> Votre choix ? : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 1:
                ajouter(catalogue,fichier);
                system("PAUSE");
                retour = 1;
                break;
            case 2:
                afficher_liste(catalogue);
                system("PAUSE");
                retour = 1;
                break;
            case 3:
                resultat = rechercher(catalogue, chaine);
                if (resultat==NULL)
                {
                    printf("\n\n >> Article Introuvable <<");
                    system("PAUSE");
                    retour = 1;
                }
                else
                {
                    do
                    {
                        if (retour2==0)
                            printf("\n");
                        retour2 = 0;
                        printf("-------------- Menu --------------\n\n\n\n\n\n");
                        printf("1\n\n) Modifier l'article %s", resultat);
                        printf("\n\n\n\n\n\n2) Supprimer l'article %s", resultat);
                        printf("\n\n\n\n --> Votre choix ? : ");
                        scanf("%d",&choix2);
                        switch (choix2)
                        {
                            case 1:
                                modifier(fichier,resultat);
                                system("PAUSE");
                                retour = 1;
                                break;
                            case 2:
                                supprimer(resultat);
                                system("PAUSE");
                                retour = 1;
                                break;
                            default:
                                printf("\n >>> Choix Invalide ! <<< \n");
                                retour2 = 1;
                                break;
                        }
                    }
                    while ((choix2!=1 && choix2!=2) || retour2==1);
                }
                free(resultat);
                free(chaine);
                break;
            case 0:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                system("PAUSE");
                exit(0);
                break;
            default:
                printf("\n >>> Choix Invalide ! <<< \n");
                retour = 1;
                break;
        }
    }
    while ((choix<0 && choix>3) || retour==1);
 
    return 0;
}
