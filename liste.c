#include "liste.h"

Liste * initialiserListe()
{
    Liste * liste = malloc(sizeof(*liste));
    Element * element = malloc(sizeof(*element));

    element->coureur = NULL;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void ajouterCoureurDebut(Liste * liste, Coureur * coureur)
{
    Element * nouveau = malloc(sizeof(*nouveau));

    nouveau->coureur = coureur;

    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
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
}

void supprimerCoureur(Liste * liste)
{
    Element * pointeur = liste->premier;
    liste->premier = liste->premier->suivant;
    free(pointeur);
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