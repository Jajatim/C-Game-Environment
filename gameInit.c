#include "includes.h"

void gameInit(anObject allObject[NB_MAX_OBJ]) {

    //0 : pad gauche
    //1 : pad droite
    //2 : Balle


    //0 : pad gauche
    allObject[0].x = 20;
    allObject[0].y = WINDOW_Y/2-100/2;
    allObject[0].w = 20;
    allObject[0].h = 100;
    allObject[0].speed = 300;

    //1 : pad droite
    allObject[1].x = WINDOW_X-20;
    allObject[1].y = WINDOW_Y/2-100/2;
    allObject[1].w = 20;
    allObject[1].h = 100;
    allObject[1].speed = 300;

    //2 : Balle
    allObject[2].x = WINDOW_X/2-20/2;
    allObject[2].y = WINDOW_Y/2-20/2;
    allObject[2].w = 20;
    allObject[2].h = 20;
    allObject[2].speed = 750;

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
