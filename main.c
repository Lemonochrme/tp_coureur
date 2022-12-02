#include <stdio.h>
#include "liste.h"



int main()
{
    Coureur * coureur1 = Creer_Coureur("Smith", "John", 20, "Equipe 1", 3600);
    Coureur * coureur2 = Creer_Coureur("Smith", "Sarah", 20, "Equipe 2", 2000);

    Liste * uneListe = initialiserListe();

    ajouterCoureurFin(uneListe, coureur1);
    ajouterCoureurFin(uneListe, coureur2);
    afficherListe(uneListe);
    
    supprimerCoureur(uneListe);
    printf("azoidazdoiazodibazoidbazoidbazoibd\n");

    afficherListe(uneListe);

    return 0;
}

