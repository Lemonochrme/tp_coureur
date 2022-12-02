/** @file */

/**
 * Classe représentative des attributs d'un coureur : nom, prénom, n° de dossard, n° équipe et temps cumulé
 */
typedef struct
{
    char nom[20];
    char prenom[20];
    int numeroDossard;
    char equipe[20];
    int tempsCumule;
}Coureur;

/**
 * Fonction permettant d'afficher les informations d'un coureur formatées dans le terminal
 */
void Afficher_Coureur(Coureur * temp);

/**
 * Fonction permettant d'ajouter le temps d'une étape a un coureur
 */
void Ajouter_Temps(Coureur * temp, int tempsTour);

/**
 * Fonction retournant un objet de type coureur : sert à créer un coureur
 */
Coureur * Creer_Coureur(char * nom, char * prenom, int numeroDossard, char * equipe, int tempsCumule);