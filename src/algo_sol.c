#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

double recherche_sol_aux(Arbre a,double prix_max, double poids_sac, double * couple_sol){
  double prix_max_g, prix_max_d;

  if(est_vide(a)){
    return prix_max;
  }

  /*Le poids des objets dans le sac est plus grands que la capacité du sac*/
  /*On étudie seulement la branche de gauche*/
  if((a->poids_br + (a->racine).poids )> poids_sac){
    return recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, couple_sol);
  }
  /*Sinon on va devoir regarder les deux branches fils*/
  else{
    prix_max_g = recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, couple_sol);
    prix_max_d = recherche_sol_aux(a->fils_droit, prix_max+ (a->racine).prix, poids_sac, couple_sol);

    if(prix_max_d>prix_max_g){
      couple_sol[0]=prix_max_d;
      if (!est_vide(a->fils_droit)) {
        if (a->fils_droit->numero_racine > couple_sol[1]) {
          couple_sol[1]=a->fils_droit->numero_racine;
        }
      }
      return prix_max_d;
    }else{
      couple_sol[0]=prix_max_g;
      if (!est_vide(a->fils_gauche)) {
        if (a->fils_gauche->numero_racine > couple_sol[1]) {
          couple_sol[1]=a->fils_gauche->numero_racine;
        }

      }
      return prix_max_g;
    }
  }

}

double * recherche_sol(Arbre arbre_jeu, double poids_sac){
  double * couple_sol;

  couple_sol=(double*)malloc(sizeof(double)*2);
  if(couple_sol==NULL){
    printf("Problème de malloc\n" );
    return NULL;
  }

  recherche_sol_aux(arbre_jeu, 0, poids_sac,couple_sol);

  return couple_sol;
}
