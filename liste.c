#include "liste.h"

Liste * initialiserListe()
{
    Liste * liste = malloc(sizeof(*liste));
    Element * element = malloc(sizeof(*element));

    element->coureur = NULL;
    element->suivant = NULL;
    liste->premier = element;

    liste->courant = liste->premier;
    liste->fin = NULL;

    return liste;
}

void ajouterCoureurDebut(Liste * liste, Coureur * coureur)
{
    Element * nouveau = malloc(sizeof(*nouveau));

    nouveau->coureur = coureur;

    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    liste->courant = nouveau;
}

void ajouterCoureurFin(Liste * liste, Coureur * coureur)
{
    Element * nouveau = malloc(sizeof(*nouveau));
    if(nouveau==NULL) exit(0);
 
    nouveau->coureur=coureur;
    nouveau->suivant=NULL;
 
    Element * p = liste->premier;
    while(p->suivant != NULL)
    {
        p = p->suivant;
    }
     
    p->suivant = nouveau;
    liste->courant = nouveau;
    liste->fin = nouveau;
}

void supprimerCoureur(Liste * liste, Element * aSupprimer)
{
    aSupprimer = liste->courant;

}

void allerDebut(Liste * liste)
{
    liste->courant = liste->premier;
}

void allerFin(Liste * liste)
{
    liste->courant = liste->fin;
}

void avancer(Liste * liste)
{
    liste->courant = liste->courant->suivant;
}

void afficherCourant(Element * courant)
{
    Afficher_Coureur(courant->coureur);
}

Coureur * retournerCourant(Element * courant)
{
    return courant->coureur;
}

void trierListe(Liste * liste)
{
    
}

void afficherListe(Liste * liste)
{
    Element * actuel = liste->premier;
    
    while(actuel != NULL)
    {
        if (actuel->coureur != NULL)
        {
            Afficher_Coureur(actuel->coureur);
        }
        actuel = actuel->suivant;
    }
}