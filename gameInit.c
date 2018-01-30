#include "includes.h"

void gameInit(anObject allObject[NB_MAX_OBJ]) {

    //Voir l'enumeration dans "defines.h" pour voir les correspondances

    //0 : pad gauche
    allObject[PAD_LEFT].x = 20;
    allObject[PAD_LEFT].y = WINDOW_Y/2-100/2;
    allObject[PAD_LEFT].w = 20;
    allObject[PAD_LEFT].h = 100;
    allObject[PAD_LEFT].speed = 300;

    //1 : pad droite
    allObject[PAD_RIGHT].x = WINDOW_X-20-20;
    allObject[PAD_RIGHT].y = WINDOW_Y/2-100/2;
    allObject[PAD_RIGHT].w = 20;
    allObject[PAD_RIGHT].h = 100;
    allObject[PAD_RIGHT].speed = 300;

    //2 : Balle
    allObject[BALL].x = WINDOW_X/2-20/2;
    allObject[BALL].y = WINDOW_Y/2-20/2;
    allObject[BALL].w = 20;
    allObject[BALL].h = 20;
    allObject[BALL].speed = 750;

    /*//3 : Score Joueur Gauche
    allObject[0].x = 100;
    allObject[0].y = 100;
    allObject[0].w = 200;
    allObject[0].h = 200;
    allObject[0].speed = 100;

    //4 : Score Joueur Droite
    allObject[0].x = 100;
    allObject[0].y = 100;
    allObject[0].w = 200;
    allObject[0].h = 200;
    allObject[0].speed = 100;*/
}
