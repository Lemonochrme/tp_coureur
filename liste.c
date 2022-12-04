#include "liste.h"
#include <stdio.h>
#include <string.h>

Liste * initialiserListe()
{
    Liste * liste = malloc(sizeof(*liste));
    Element * element = malloc(sizeof(*element));

    element->coureur = NULL;  // La structure coureur est initialisée à NULL
    element->suivant = NULL;  // Premier element = dernier element : il pointe donc vers NULL

    //liste->premier = element; // Le premier element de la liste est stocké dans le pointeur premier : Non utilisé car déclaré dans fonction ajouterCoureurFin
    liste->fin = liste->premier;     // Le dernier element est dans ce cas aussi le premier

    liste->courant = liste->premier; // Le curseur est positionné sur le premier élement
    liste->taille = 0;

    return liste;
}

void ajouterCoureurDebut(Liste * liste, Coureur * coureur)
{
    Element * nouveau = malloc(sizeof(*nouveau)); // Créer nouvel élement

    nouveau->coureur = coureur; // Mettre les données de coureur dedans

    // On ajoute un element au début : il faut donc faire pointer suivant vers
    // le premier de la liste puis modifier premier pour le faire pointer vers le nouvel element
    nouveau->suivant = liste->premier; 
    liste->premier = nouveau;

    liste->taille = liste->taille + 1;
}

int tailleListe(Liste * liste)
{
    return liste->taille;
}

void ajouterCoureurFin(Liste * liste, Coureur * coureur)
{
    // Algo : creer element puis faire pointer suivant vers null car il va devenir le dernier
    // element.
    // Parcourir la liste et trouver le dernier element
    // Le suivant du dernier element devra pointer vers le nouvel element

    Element * nouveau = malloc(sizeof(*nouveau)); // Création du nouvel element
    nouveau->suivant = NULL;
    nouveau->coureur = coureur;

    if (liste->premier == NULL)
    {
        liste->premier = nouveau;
        liste->courant = liste->premier; // Positionner curseur sur dernier element
    }
    else
    {
        Element * dernier = liste->premier;

        while(dernier->suivant != NULL)
        {
            dernier = dernier->suivant;
        }
        dernier->suivant = nouveau;
        liste->courant = nouveau; // Positionner curseur sur dernier element
        liste->fin = nouveau; // Posionner pointeur fin sur le dernier element
    }

    liste->taille = liste->taille + 1;
}


void supprimerCoureur(Liste * liste)
{
    Element * aSuppr = liste->courant;
    
    Element * prev = liste->premier;
    while (prev->suivant != liste->courant)
    {
        prev = prev->suivant;
    }
    
    prev->suivant = liste->courant->suivant;

    liste->taille = liste->taille - 1;
    free(aSuppr);
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
    int swapped;
    Element * temp; 
    Element * ptr = NULL; 
  
    do
    { 
        swapped = 0; 
        temp = liste->premier; 
  
        while (temp->suivant != ptr) 
        { 
            if (temp->coureur->tempsCumule > temp->suivant->coureur->tempsCumule) 
            { 
                swap(temp, temp->suivant); 
                swapped = 1; 
            } 
            temp = temp->suivant; 
        } 
        ptr = temp; 
    } 
    while (swapped); 
}

void swap(Element * a, Element * b)
{
    Coureur * temp = a->coureur; 
    a->coureur = b->coureur; 
    b->coureur = temp; 
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

void actualiserTemps(Liste * liste)
{
    Element * curseur = liste->premier;
    int tempsEtape = 20;

    while (curseur != NULL)
    {
        if (curseur->coureur != NULL)
        {
            curseur->coureur->tempsCumule = curseur->coureur->tempsCumule + tempsEtape;
        }

    }
}

void supprimerEquipesInvalides(Liste * liste)
{
    int cptCoureur;
    char * tempEquipe;

    // Scanner la liste pour trouver moins de 5 occurence d'une équipe
    // Si moins de 5 occurences : supprimer tous les coureurs de l'équipe
    Element * curseur = liste->premier;
    
    while (curseur->suivant != NULL)
    {
        cptCoureur = 0;
        tempEquipe = curseur->coureur->equipe;

        Element * temp = liste->premier;
        while (temp->suivant != NULL)
        {
            if (strstr(temp->coureur->equipe, tempEquipe) != NULL)
            {
                cptCoureur++;
            }
            temp = temp->suivant;
        }

        if (cptCoureur < 5)
        {
            printf("%s à moins de 5 coureurs\n", tempEquipe);
            // Supprimer
        }

        curseur = curseur->suivant;
    }




}