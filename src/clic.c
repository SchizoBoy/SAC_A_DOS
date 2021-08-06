#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

int saisie_obj(){
  int x,y;

  MLV_wait_mouse(&x,&y);

  if(99<x && x < 201 && 99<y && y<151){
    return 0;
  }
  if(99<x && x < 201 && 169<y && y<211){
    return 1;
  }
  if(99<x && x < 201 && 239<y && y<291){
    return 2;
  }
  if(99<x && x < 201 && 309<y && y<361){
    return 3;
  }
  if(99<x && x < 201 && 379<y && y<431){
    return 4;
  }
  if(99<x && x < 201 && 449<y && y<501){
    return 5;
  }

  return -1;
}

int saisie_valider(){
  int x,y;

  MLV_wait_mouse(&x,&y);

  if(449<x && x<519 && 549<y && y<581){
    return 1;
  }
  return 0;
}
