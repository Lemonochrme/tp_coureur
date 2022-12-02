#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "coureur.h"

Coureur * Creer_Coureur(char * nom, char * prenom, int numeroDossard, char * equipe, int tempsCumule)
{
    Coureur * temp = malloc(sizeof(Coureur));

    strcpy(temp->nom, nom);
    strcpy(temp->prenom, prenom);
    strcpy(temp->equipe, equipe);
    temp->numeroDossard = numeroDossard;
    temp->tempsCumule = tempsCumule;

    return temp;
}

void Ajouter_Temps(Coureur * temp, int tempsTour)
{
    temp->tempsCumule = temp->tempsCumule + tempsTour;
}

void Afficher_Coureur(Coureur * temp)
{
    int h,m,s;

    s = temp->tempsCumule;

    /*Conversion secondes -> heures minutes secondes*/
    h = s / 3600;
	s = s % 3600;
	m = s / 60;  
	s = s % 60;

    printf("================= FICHE COUREUR ================\n");
    printf("Nom : %s\n", temp->nom);
    printf("Prénom : %s\n", temp->prenom);
    printf("Numéro de dossard : %d\n", temp->numeroDossard);
    printf("Equipe : %s\n", temp->equipe);
    printf("Temps cumulé : %dh %dmin %ds\n",h,m,s);	
}
