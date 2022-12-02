#include <stddef.h>
#include <stdlib.h>
#include "coureur.h"

typedef struct Element Element;
struct Element
{
    Coureur * coureur;
    Element * suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element * premier;
    int nombre_elements;
};

Liste * initialiserListe();

void ajouterCoureurDebut(Liste * liste, Coureur * coureur);

void ajouterCoureurFin(Liste * liste, Coureur * coureur);

void supprimerCoureur(Liste * liste);

void afficherListe(Liste * liste);
