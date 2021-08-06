// Fonctions d'erreur

#include <stdlib.h>
#include <stdio.h>

/* Fonction affichant une erreur et arrêtant le programme */
void erreur(char *error){
  perror(error);
  exit(-1);
}
