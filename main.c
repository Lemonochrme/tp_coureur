#include <stdio.h>
#include "liste.h"

#define curseur uneListe->courant

int main()
{
    Coureur * coureur1 = Creer_Coureur("Smith", "John", 20, "Equipe 1", 3600);
    Coureur * coureur2 = Creer_Coureur("Smith", "Sarah", 20, "Equipe 2", 2000);
    Coureur * coureur3 = Creer_Coureur("Hammer", "Abigail", 20, "Equipe 3", 4000);
    Coureur * coureur4 = Creer_Coureur("Hammer", "Abigail", 20, "Equipe 4", 2300);
    Coureur * coureur5 = Creer_Coureur("Hammer", "Abigail", 20, "Equipe 5", 6000);

    Liste * uneListe = initialiserListe();

    ajouterCoureurFin(uneListe, coureur1);
    ajouterCoureurFin(uneListe, coureur2);
    ajouterCoureurFin(uneListe, coureur3);
    ajouterCoureurFin(uneListe, coureur4);
    ajouterCoureurFin(uneListe, coureur5);

    trierListe(uneListe);

    afficherListe(uneListe);


    return 0;
}

