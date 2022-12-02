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
    Element * courant;
    Element * fin;
    int nombre_elements;
};

Liste * initialiserListe();

void ajouterCoureurDebut(Liste * liste, Coureur * coureur);

void ajouterCoureurFin(Liste * liste, Coureur * coureur);

void supprimerCoureur(Liste * liste, Element * aSupprimer);

void afficherListe(Liste * liste);

void afficherCourant(Element * courant);

Coureur * retournerCourant(Element * courant);

void allerDebut(Liste * liste);

void allerFin(Liste * liste);

void avancer(Liste * liste);

void trierListe(Liste * liste);
