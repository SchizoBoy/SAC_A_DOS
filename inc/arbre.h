// Proto fonctions arbres

#ifndef ARBRES_H_
#define ARBRES_H_

#include <erreur.h>

typedef struct Objet{
  double prix;
  double poids;
}Objet;

/* Création de la structure Noeud */
typedef struct Noeud{
  Objet racine;
  struct Noeud *fils_gauche;
  struct Noeud *fils_droit;
  double prix_br;     // Prix de la branche
  double poids_br;    // Poids de la branche
  int numero_racine;  // numero de racine (choix unique)
}Noeud;

/* Création des arbres */
typedef Noeud* Arbre;

/* Fonction vérifiant si un arbre est vide, soit si il est égal à NULL */
int est_vide(Arbre a);

/* Fonction retournant un arbre vide soit NULL */
Arbre creer_arbre_vide();

/*Fonction permettant de créer un noeud avec sa racine*/
Arbre creer_noeud(Objet racine, double prix, double poids, int numero_racine);

/* Fonction permettant de créer un arbre avec ses fils et sa racine */
Arbre creer_arbre(
  Objet racine,
  Arbre fils_gauche,
  Arbre fils_droit,
  double prix,
  double poids,
  int numero_racine
);

/* Fonction permettant d'insérer le fils gauche d'un arbre */
Arbre inserer_fils_gauche(Arbre a, Arbre fils_gauche);

/* Fonction permettant d'insérer le fils droit d'un arbre */
Arbre inserer_fils_droit(Arbre a, Arbre fils_droit);

/* Fonction permettant d'afficher un arbre dans le terminal */
void afficher_arbre(Arbre a);

/* Fonction permettant d'afficher un arbre dans le terminal */
int est_feuille(Arbre a);

/* Permet de détruire un arbre */
void detruire_arbre(Arbre a);

// Crée un arbre avec des objets ayant un prix et un poids
Arbre creer_arbre_objet(Objet *liste_objet, int nb_obj);

// Fonction de conversion d'entier en binaire sous forme de tableau d'entier
int *int_to_binaire(int puissance);

// Fonction analysant le binaire sortit de l'analyse de l'arbre
void choix_objet(Objet liste_obj, int *binaire);

#endif
