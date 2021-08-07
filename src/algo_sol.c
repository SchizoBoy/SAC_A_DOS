#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

double * recherche_sol_aux(Arbre a,double prix_max, double poids_sac, int pos_arbre, double * couple_sol){
  double couple_max_g[2], couple_max_d[2];

  if(est_vide(a)){
    return couple_sol;
  }

  /*Le poids des objets dans le sac est plus grands que la capacité du sac*/
  /*On étudie seulement la branche de gauche*/
  if((a->poids_br + (a->racine).poids )> poids_sac){
    return recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, pos_arbre+1, couple_sol);
  }
  /*Sinon on va devoir regarder les deux branches fils*/
  else{
    couple_max_g[0] = (recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, pos_arbre+1, couple_sol))[0];
    couple_max_g[1] = (recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, pos_arbre+1, couple_sol))[1];
    couple_max_d[0] = (recherche_sol_aux(a->fils_droit, prix_max+ (a->racine).prix, poids_sac, pos_arbre+1, couple_sol))[0];
    couple_max_d[1] = (recherche_sol_aux(a->fils_droit, prix_max+ (a->racine).prix, poids_sac, pos_arbre+1, couple_sol))[1];

    if(couple_max_d[0]>couple_max_g[0]){
      couple_sol[0]=couple_max_d[0];
      couple_sol[1]= couple_max_d[1];
      return couple_sol;
    }else{
      couple_sol[0]=couple_max_g[0];
      couple_sol[1]= couple_max_d[1];
      return couple_sol;
    }
  }

}

double * recherche_sol(Arbre arbre_jeu, double poids_sac){
  double couple_sol[2] = {0.0}; /*La première valeur correspond au prix maximum,
  et la deuxième à une solution pour avoir ce prix*/
  couple_sol[0]= (recherche_sol_aux(arbre_jeu, 0, poids_sac, 0, couple_sol))[0];
  couple_sol[1]= (recherche_sol_aux(arbre_jeu, 0, poids_sac, 0, couple_sol))[1];
  return couple_sol;
}
