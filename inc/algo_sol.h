#ifndef ALGO_SOL_H
#define  ALGO_SOL_H

#include "arbre.h"

double * recherche_sol_aux(Arbre a, double prix_max, double poids_sac, int pos_arbre, double * couple_sol);
double * recherche_sol(Arbre arbre_jeu,  double poids_sac);

#endif
