// Fonctions arbres

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "arbre.h"

/* Fonction vérifiant si un arbre est vide, soit si il est égal à NULL */
int est_vide(Arbre a){
  return (a == NULL); /* Retourne 1 si a est égal à NULL, 0 sinon */
}

/* Fonction retournant un arbre vide soit NULL */
Arbre creer_arbre_vide(){
  return NULL;  /* On associe l'arbre vide à la valer NULL */
}

/* Fonction permettant de renvoyer la racine de l'arbre */
Objet racine(Arbre a){
  if(est_vide(a)){  /* Si a est vide, il y a une erreur */
    erreur("Erreur, un arbre vide ne possède pas de racine : racine");
  }
  return a->racine;
}

/*Fonction permettant de créer un noeud avec sa racine*/
Arbre creer_noeud(Objet racine, double prix, double poids){
  Arbre a = creer_arbre_vide();         /* On crée un arbre/noeud vide */

  a = (Noeud *)malloc(sizeof(Noeud));   /* Allocation de l'abre en mémoire */
  if(a == NULL){                        /* Vérification de l'allocation */
    erreur("Erreur d'allocation dans la fonction creer_noeud.\n");
  }

  a->racine = racine;                   /* On insère la racine de l'arbre */
  a->fils_gauche = creer_arbre_vide();  /* Son fils gauche est l'arbre vide */
  a->fils_droit = creer_arbre_vide();   /* De même que son fils droit */
  a->prix_br = prix;
  a->poids_br = poids;
  return a;
}


/* Fonction permettant de créer un arbre avec ses fils et sa racine */
Arbre creer_arbre(
  Objet racine,
  Arbre fils_gauche,
  Arbre fils_droit,
  double prix,
  double poids
){
  Arbre a = creer_noeud(racine, prix, poids);  /* On crée un noeud */
  a->fils_gauche = fils_gauche;   /* On lui greffe son fils gauche */
  a->fils_droit = fils_droit;     /* On lui greffe son fils droit */

  return a;                       /* L'arbre fraichement créé est retourné */
}

/* Fonction permettant d'insérer le fils gauche d'un arbre */
Arbre inserer_fils_gauche(Arbre a, Arbre fils_gauche){
  a->fils_gauche = fils_gauche;   /* On lui greffe son fils gauche */
  return a;
}

/* Fonction permettant d'insérer le fils droit d'un arbre */
Arbre inserer_fils_droit(Arbre a, Arbre fils_droit){
  a->fils_droit = fils_droit;     /* On lui greffe son fils droit */
  return a;
}

/* Fonction locale recursive permettant de connaître la profondeur d'un arbre */
int profondeur_arbre(Arbre a){
  if(est_vide(a)){  /* Si l'arbre est vide, on renvoie 0 */
    return 0;
  }
  /* Sinon sinon on renvoie la profondeur du fils le plus profond + 1 */
  if(profondeur_arbre(a->fils_droit) > profondeur_arbre(a->fils_gauche)){
    return 1+profondeur_arbre(a->fils_droit);
  }
  else{
    return 1+profondeur_arbre(a->fils_gauche);
  }
}


/* Fonction locale recursive permettant d'afficher un noeud (ie un arbre) */
void aff_noeud(Arbre a, int prof, int max_prof){
  int i;

  if(!est_vide(a)) {    /* Si le noeud n'est pas vide : */
    aff_noeud(a->fils_droit, prof+1, max_prof); /* On affiche le fils droit */
    for (i = 0; i < prof; i++){
      printf("                      ");
    }
    printf("%f,%f <\n", a->prix_br, a->poids_br);
    aff_noeud(a->fils_gauche, prof+1, max_prof); /* On affiche le fils gauche */
  }
  else{                 /* Sinon (ie si le noeud est vide) : */
    for (i = 0; i < prof; i++) {
      printf("                      ");
    }
    printf("NULL\n");     /* On affiche NULL puisque le noeud est vide */
  }
}

/* Fonction permettant d'afficher un arbre dans le terminal */
void afficher_arbre(Arbre a){
  aff_noeud(a, 0, profondeur_arbre(a));
}

/* Fonction permettant de savoir si l'arbre (ou sous-arbre) est une feuille */
int est_feuille(Arbre a){
  if(a == NULL){  /* Si l'arbre est vide il n'est pas une feuille */
    erreur("Erreur, arbre vide passé en paramètre de la fonction est_feuille");
  }
  /* Un arbre dont les deux fils sont vides est une feuille */
  else if(a->fils_gauche == NULL && a->fils_droit == NULL){
    return 1;
  }

  /* Sinon, l'arbre (ou sous-arbre) n'est pas une feuille */
  return 0;
}

/* Permet de détruire un arbre */
void detruire_arbre(Arbre a){
  if(est_feuille(a)){ /* Si l'arbre est une feuille on le libère */
    free(a);
  }
  else{     /* Sinon on libère ses fils non vides */
    /* On libère le fils gauche si il n'est pas vide */
    if(!est_vide(a->fils_gauche)){
      detruire_arbre(a->fils_gauche);
    }
    /* On libère le fils droit si il n'est pas vide */
    if(!est_vide(a->fils_droit)){
      detruire_arbre(a->fils_droit);
    }
    free(a);    /* Enfin on libère l'arbre lui-même */
  }
}

// Fonctions auxiliaire de creer_arbre_objet()
Arbre creer_arbre_objet_aux(
  Objet *liste_objet,
  int nb_obj,
  int pos,
  double cout,
  double poids
){
  Objet racine;
  Objet bouchon;

  if(pos == nb_obj){
    racine.prix = liste_objet[pos-1].prix;
    racine.poids = liste_objet[pos-1].poids;
    bouchon.prix = 0;
    bouchon.poids = 0;

    return creer_arbre(
      racine,
      creer_noeud(bouchon, cout, poids),
      creer_noeud(
        bouchon,
        cout+liste_objet[pos-1].prix,
        poids+liste_objet[pos-1].poids
      ),
      cout,
      poids
    );
  }
  else{
    racine.prix = liste_objet[pos-1].prix;
    racine.poids = liste_objet[pos-1].poids;

    return creer_arbre(
      racine,
      creer_arbre_objet_aux(liste_objet, nb_obj, pos+1, cout, poids),
      creer_arbre_objet_aux(
        liste_objet,
        nb_obj,
        pos+1,
        cout+liste_objet[pos-1].prix,
        poids+liste_objet[pos-1].poids
      ),
      cout,
      poids
    );
  }
}

// Crée un arbre avec des objets ayant un prix et un poids
Arbre creer_arbre_objet(Objet *liste_objet, int nb_obj){
  return creer_arbre_objet_aux(liste_objet, nb_obj, 1, .0, .0);
}
