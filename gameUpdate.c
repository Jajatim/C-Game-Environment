#include "includes.h"

void gameUpdate(Uint32 deltatime,Keyboard *pKEYBOARD,anObject allObject[NB_MAX_OBJ]) {

    //0 : pad gauche
    //1 : pad droite
    //2 : Balle


    //0 : pad gauche
    if (pKEYBOARD->Keyz==1) {
        allObject[0].y -= allObject[0].speed*deltatime/1000;
    }
    /*if (pKEYBOARD->Keyq==1) {
        allObject[0].x -= allObject[0].speed*deltatime/1000;
    }*/
    if (pKEYBOARD->Keys==1) {
        allObject[0].y += allObject[0].speed*deltatime/1000;
    }
    /*if (pKEYBOARD->Keyd==1) {
        allObject[0].x += allObject[0].speed*deltatime/1000;
    }*/


    //1 : pad droite
    if (pKEYBOARD->ArrowUp==1) {
        allObject[1].y -= allObject[1].speed*deltatime/1000;
    }
    /*if (pKEYBOARD->ArrowLeft==1) {
        allObject[1].x -= allObject[1].speed*deltatime/1000;
    }*/
    if (pKEYBOARD->ArrowDown==1) {
        allObject[1].y += allObject[1].speed*deltatime/1000;
    }
    /*if (pKEYBOARD->ArrowRight==1) {
        allObject[1].x += allObject[1].speed*deltatime/1000;
    }*/


    //2 : Balle
    static float dirX=1; //Coefficient de déplacement X, ici la balle va uniquement à droite sur l'axe X
    static float dirY=0; //Coefficient de déplacement Y, ici la balle va tout droit sur l'axe Y
    //La somme des valeurs absolues de X et Y doit toujours être égale à 1.

    //Collision plafond
    if (allObject[2].y<0) {
        dirY *= -1;
        allObject[2].y=1;
    }

    //Collision plancher
    if (allObject[2].y+allObject[2].h>WINDOW_Y) {
        dirY *= -1;
        allObject[2].y=WINDOW_Y-allObject[2].h-1;
    }

    //Verif collision à gauche (on vérifie cette condition quand la balle est à 50pixels du pad)
    if (allObject[2].x<allObject[0].x+50 && isColliding(allObject,2,0)==1) {
        //S'il y a collision, on vérifie compare les Y de la balle et du pad pour calculer l'angle de rebond
        dirY = ((allObject[2].y + (allObject[2].h/2)) - allObject[0].y) / allObject[0].h;
        dirY -= 0.5;

        if (dirY<0) dirX = 1+dirY;
        else dirX = 1-dirY;

        printf("dir X : %f / dir Y : %f\n",dirX,dirY);
    }

    //Verif collision à droite (on vérifie cette condition quand la balle est à 50pixels du pad)
    if (allObject[2].x>allObject[1].x-50 && isColliding(allObject,2,1)==1) {
        //S'il y a collision, on vérifie compare les Y de la balle et du pad pour calculer l'angle de rebond
        dirY = ((allObject[2].y + (allObject[2].h/2)) - allObject[1].y) / allObject[1].h;
        dirY -= 0.5;

        if (dirY<0) dirX = 1+dirY;
        else dirX = 1-dirY;

        dirX *= -1;

        printf("dir X : %f / dir Y : %f\n",dirX,dirY);
    }

    allObject[2].x += allObject[2].speed*deltatime/1000 * dirX;
    allObject[2].y += allObject[2].speed*deltatime/1000 * dirY;

    if (pKEYBOARD->Space==1) {
        gameInit(allObject);
        dirX=1;
        dirY=0;
    }
}


int isColliding(anObject allObject[NB_MAX_OBJ], int a, int b) {
    //Pas de collision en haut ?
    if (allObject[a].x>allObject[b].x+allObject[b].w) return 0;

    //Pas de collision en bas ?
    if (allObject[a].x+allObject[a].w<allObject[b].x) return 0;

    //Pas de collision à gauche ?
    if (allObject[a].y>allObject[b].y+allObject[b].h) return 0;

    //Pas de collision à droite ?
    if (allObject[a].y+allObject[a].h<allObject[b].y) return 0;

    return 1;
}
