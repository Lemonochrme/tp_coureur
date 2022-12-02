typedef struct
{
    char nom[20];
    char prenom[20];
    int numeroDossard;
    char equipe[20];
    int tempsCumule;
}Coureur;

void Afficher_Coureur(Coureur * temp);

void Ajouter_Temps(Coureur * temp, int tempsTour);

Coureur * Creer_Coureur(char * nom, char * prenom, int numeroDossard, char * equipe, int tempsCumule);