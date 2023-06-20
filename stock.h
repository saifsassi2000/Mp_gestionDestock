#ifndef STOCK_H  // header guard
#define STOCK_H

struct article
{
    char nom[20];
    char nom_du_fabricant[20];
    char categorie[20];
    char pays[20];
    char date_de_fabrication[20];
};
typedef struct article article;
#endif
