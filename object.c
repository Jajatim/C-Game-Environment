#include "includes.h"

void initObject(anObject allObject[NB_MAX_OBJ]) {
    int i;
    for (i=0;i<NB_MAX_OBJ;i++) {
        allObject[i].x=0.0;
        allObject[i].y=0.0;
        allObject[i].w=0.0;
        allObject[i].h=0.0;
        allObject[i].speed=0.0;
    }
}

/* A REVOIR
void createObject(anObject *thisObject) {
    //On alloue la mémoire de la table des matrices


    //On fait appel à l'init
    initObject(thisObject,1);
}


void initObject(anObject *thisObject,int dontDestroy) {
    //On détruit l'objet si besoin
    if (dontDestroy==1) destroyObject(thisObject);

    //On initialise tout à la valeur par défaut
    thisObject->isDead=0;
    thisObject->isMovable=0;
    thisObject->isRenderable=0;
    thisObject->isCollisionable=0;
    thisObject->type=0;
    thisObject->x=0;
    thisObject->y=0;
    thisObject->w=0;
    thisObject->h=0;
    thisObject->speed=0;
    thisObject->pSpriteSheet=NULL;
    thisObject->nbAnimations=0;
    thisObject->maxFramesPerAnim=0;
    thisObject->tableAnimations = createTable(thisObject->nbAnimations,thisObject->maxFramesPerAnim);
}


void destroyObject(anObject *thisObject) {
    //Il faut libérer :
    // - Surface
    // - Mémoire allouée à la matrice des animations
}


//Allocation de mémoire pour matrice à 2 dimensions
int** createTable(int lignes, int colones)
{
    int** tableau;
    int* data;
    int i;

    if(lignes <= 0 || colones <= 0)
    {
        return NULL;
    }

    tableau = (int**) malloc(lignes*colones*sizeof(int) + lignes*sizeof(int*));
    if(tableau == NULL)
    {
        return NULL;
    }

    for(i=0,data=(int*)(tableau+lignes); i<lignes; i++,data+=colones)
    {
        tableau[i] = data;
    }

    return tableau;
}
*/
