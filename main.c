#include <stdio.h>
#include <string.h>
#include <time.h>
#include "liste.h"

int main()
{
    srand( time( NULL ) );

    int nbEtapes = 0;
    int nbEquipes = 0;

    int tempDossard;
    char * tempNom;
    char * tempPrenom;
    char tempEquipe[40];

    Liste * tempListe = initialiserListe();

    FILE* file = fopen("file.txt", "r"); 

    if(!file)
        return -1;

    char line[40];
    int cptLine = 0;

    while (fgets(line, sizeof(line), file)) 
    {
        cptLine++;

        //Numéro de dossard, Nom, Prénom
        if (cptLine == 1)
            nbEtapes = atoi(line);
        else if (cptLine == 2)
            nbEquipes = atoi(line);
        else if (strstr(line, ",") == NULL) // Détection d'une équipe
        {
            line[strlen(line) - 1] = '\0';
            strcpy(tempEquipe, line);
        }
        else
        {
            line[strlen(line) - 1] = '\0'; // Enlever le char '\n' a la fin du string
            char * token = strtok(line, ",");
            int cptToken = 0;
            while( token != NULL )
            {
                //printf( "%s\n", token);

                if (cptToken == 0)
                    tempDossard = atoi(token);
                if (cptToken == 1)
                    tempNom = token;
                if (cptToken == 2)
                    tempPrenom = token;
                cptToken++;
                
                if (cptToken == 3)
                {
                    Coureur * temp = Creer_Coureur(tempNom, tempPrenom, tempDossard, tempEquipe, rand() % 4001);
                    ajouterCoureurFin(tempListe, temp);
                }
                
                token = strtok(NULL, ",");
            }  
        }  
    }

    //supprimerEquipesInvalides(tempListe);

    trierListe(tempListe);
    afficherListe(tempListe);




    fclose(file);

    return 0;
}

