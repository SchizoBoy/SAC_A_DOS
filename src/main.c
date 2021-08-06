#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

int main(void){
  Arbre arbre_obj;
  Objet liste_obj[4];
  int i;

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

  exit(0);
}
