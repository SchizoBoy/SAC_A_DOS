#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

void fenetre(){
  MLV_create_window("Sac à dos magique",
                    "Sac à dos magique",
                    600, 600);

  MLV_draw_text(150, 20,
                "Jeu du sac à dos magique ! ",
                MLV_COLOR_WHITE);

  /*Création des objets*/
  MLV_draw_filled_rectangle(100, 100, 100, 50, MLV_COLOR_RED);
  MLV_draw_filled_rectangle(100, 170, 100, 50, MLV_COLOR_ORANGE);
  MLV_draw_filled_rectangle(100, 240, 100, 50, MLV_COLOR_YELLOW);
  MLV_draw_filled_rectangle(100, 310, 100, 50, MLV_COLOR_GREEN);
  MLV_draw_filled_rectangle(100, 380, 100, 50, MLV_COLOR_BLUE);
  MLV_draw_filled_rectangle(100, 450, 100, 50, MLV_COLOR_PURPLE);


  /*Création d'un "bouton" validé */
  MLV_draw_filled_rectangle(450, 550, 70, 30, MLV_COLOR_WHITE);
  MLV_draw_text(460, 560,
                "Valider",
                MLV_COLOR_BLACK);

  MLV_actualise_window();
  MLV_wait_seconds(3000);
  MLV_free_window();

}
