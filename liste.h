#include <stddef.h>
#include <stdlib.h>
#include "coureur.h"

/** @file */

/**
 * Classe définissant les élements de la liste
 */
typedef struct Element Element;
struct Element
{
    Coureur * coureur;
    Element * suivant; // Pointeur vers l'élement suivant
};

/**
 * Liste composée de trois pointeur sur element permettant de naviguer au travers de la liste
 */
typedef struct Liste Liste;
struct Liste
{
    Element * premier; // Pointeur vers premier élement de la liste
    Element * courant; // Poiteur vers l'élement courant
    Element * fin;     // Pointeur vers la fin de la liste
    int taille;
};

/**
 * Fonction permettant d'initialiser une liste en allouant dynamiquement de la mémoire
 */
Liste * initialiserListe();

/**
 * Fonction permettant d'ajouter un coureur au début de la liste
 */
void ajouterCoureurDebut(Liste * liste, Coureur * coureur);

/**
 * Fonction permettant d'ajouter un coureur à la fin de la liste
 */
void ajouterCoureurFin(Liste * liste, Coureur * coureur);

/**
 * Fonction permettant de supprimer le coureur contenu dabs l'élement courant
 */
void supprimerCoureur(Liste * liste);

/**
 * Fonction permettant d'afficher l'entièreté de la liste
 */
void afficherListe(Liste * liste);

/**
 * Fonction permettant d'afficher un coureur précis
 */
void afficherCourant(Element * courant);

/**
 * Fonction permettant de retourner un coureur précis
 */
Coureur * retournerCourant(Element * courant);

/**
 * Fonction permettant de positionner le curseur au début de la liste
 */
void allerDebut(Liste * liste);

/**
 * Fonction permettant de positionner le curseur à la fin de la liste
 */
void allerFin(Liste * liste);

/**
 * Fonction permettant d'avancer le curseur d'un élement
 */
void avancer(Liste * liste);

/**
 * Fonction permettant de trier les coureurs en fonction de leur performance
 */
void trierListe(Liste * liste);

/**
 * Fonction permettant d'échanger deux élements
 */
void swap(Element * a, Element * b);

/**
 * Fonction renvoyant la taille de la liste
 */
int tailleListe(Liste * liste);

/**
 * Fonction ajoutant le temps de l'étape à tous les participants
 */
void actualiserTemps(Liste * liste);

void supprimerEquipesInvalides(Liste * liste);