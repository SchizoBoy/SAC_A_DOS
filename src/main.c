#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include "algo_sol.h"
#include "graphisme.h"

int main(void){

  Arbre arbre_obj;
  Objet liste_obj[4];
  double *solution;
  double max;
  int *binaire;
  int i, poids_sac;

  poids_sac= 70;
  liste_obj[0].prix = 42.56;
  liste_obj[0].poids = 3.15;

  liste_obj[1].prix = 5.27;
  liste_obj[1].poids = 325.96;

  liste_obj[2].prix = 102.34;
  liste_obj[2].poids = 52.81;

  for(i = 0; i < 3; i++){
    printf("Objet %d : %fe, %f k\n", i, liste_obj[i].prix, liste_obj[i].poids);
  }

  arbre_obj = creer_arbre_objet(liste_obj, 3);
  afficher_arbre(arbre_obj);
  max = recherche_sol(arbre_obj, poids_sac)[0];
  printf("VOICI LE MAXIMUM : %f \n", max );

  solution = recherche_sol(arbre_obj, 70);
  binaire = int_to_binaire((int)solution[1]);

  putchar('\n');

  choix_objet(liste_obj, binaire, 70);
  // fenetre();

  exit(0);
}
