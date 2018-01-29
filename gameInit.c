#include "includes.h"

void gameInit(anObject allObject[NB_MAX_OBJ]) {

    //Création de l'objet 0 : un rectangle de test
    allObject[0].x = 100;
    allObject[0].y = 100;
    allObject[0].w = 200;
    allObject[0].h = 200;
    allObject[0].speed = 100;

    //Création de l'objet 1 : un rectangle de test
    allObject[1].x = 0;
    allObject[1].y = 0;
    allObject[1].w = 50;
    allObject[1].h = 50;
    allObject[1].speed = 100;
}
