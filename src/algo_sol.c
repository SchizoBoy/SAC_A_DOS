#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

double recherche_sol_aux(Arbre a,double prix_max, double poids_sac, int pos_arbre){
  double prix_max_g, prix_max_d;

  if(est_vide(a)){
    return prix_max;
  }

  /*Le poids des objets dans le sac est plus grands que la capacité du sac*/
  /*On étudie seulement la branche de gauche*/
  if((a->poids_br + (a->racine).poids )> poids_sac){
    return recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, pos_arbre+1);
  }
  /*Sinon on va devoir regarder les deux branches fils*/
  else{
    prix_max_g = recherche_sol_aux(a->fils_gauche, prix_max, poids_sac, pos_arbre+1);
    prix_max_d = recherche_sol_aux(a->fils_droit, prix_max+ (a->racine).prix, poids_sac, pos_arbre+1);

    if(prix_max_d>prix_max_g){
      return prix_max_d;
    }else{
      return prix_max_g;
    }
  }

}

double recherche_sol(Arbre arbre_jeu, double poids_sac){
  double prix_max;
  prix_max = recherche_sol_aux(arbre_jeu, 0, poids_sac, 0);
  return prix_max;
}
