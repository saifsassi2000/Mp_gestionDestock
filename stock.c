#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stock.h"
void ajouter(FILE* catalogue, FILE* fichier)
{
    article a;
    printf("\n -> nom ? : ");
    scanf("%s",a.nom);
    printf("\n -> nom du fabricant ? : ");
    scanf("%s",a.nom_du_fabricant);
    printf("\n -> categorie ? : ");
    scanf("%s",a.categorie);
    printf("\n -> pays d'origine ? : ");
    scanf("%s",a.pays);
    printf("\n -> date de fabrication ? : ");
    scanf("%s",a.date_de_fabrication);
     
    if((fichier = fopen(a.nom, "wb")) != NULL)
    {
        fwrite(&a, sizeof(article), 1, fichier);
        fclose(fichier);
    }
    else
    {
        printf("Impossible de créer le fichier  : %s\n", a.nom);
    }
     
    if((catalogue = fopen("Catalogue", "a")) != NULL)
    {
        fprintf(catalogue, a.nom, "\n");
        fclose(catalogue);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier : Catalogue\n");
    }
     
    printf("\n\n\n > Vous avez cree l'article ' %s",a.nom);
    printf("' avec succses !\n\n\n");
}
 
void afficher_liste(FILE* catalogue)
{
    char chaine[20];
    printf("\n\n --> Voici la liste des articles : \n\n");
    catalogue = fopen("Catalogue", "r");
    if (catalogue != NULL)
    {
        while (fgets(chaine, 20, catalogue) != NULL)
        {
            printf("\n - %s\n\n\n", chaine);
        }
        fclose(catalogue);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier : Catalogue\n");
    }
}
 
char* rechercher(FILE* catalogue, char* chaine)
{
    char recherche[20];
    printf("\n -> Rechercher : ");
    scanf("%s",recherche);
    catalogue = fopen("Catalogue", "r");
     
    //Cette ligne est pour remplacer le \n de la chaine par un '\0'
    chaine[strlen(chaine)] = '\0';
     
    if (catalogue != NULL)
    {
        while (fgets(chaine, 20, catalogue) != NULL)
        {
            if ((strcmp(chaine, recherche)==0))
            {
                return chaine;
            }
            else
                return NULL;
        }
        fclose(catalogue);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier : Catalogue\n");
    }
     
    return NULL;
}
 
void modifier(FILE* fichier, char* chaine)
{
    article a;
    printf("\n\n -> Veuillez saisir les nouvelles valeurs de l'article %s", chaine);
    printf(" : ");
    fflush(stdout);
    int i;
    for(i=0;i<20;i++)
    {
        a.nom[i] = chaine[i];
    }
    printf("\n -> nom du fabricant ? : ");
    scanf("%s",a.nom_du_fabricant);
    printf("\n -> categorie ? : ");
    scanf("%s",a.categorie);
    printf("\n -> pays d'origine ? : ");
    scanf("%s",a.pays);
    printf("\n -> date de fabrication ? : ");
    scanf("%s",a.date_de_fabrication);
    if((fichier = fopen(a.nom, "wb+")) != NULL)
    {
        fwrite(&a, sizeof(article), 1, fichier);
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir/créer le fichier : %s\n", a.nom);
    }
     
    printf("\n\n\n > Vous avez modifie l'article ' %s", a.nom);
    printf("' avec succses !\n\n\n");
}
 
void supprimer(char* chaine)
{
    remove(chaine);
}
 
 
