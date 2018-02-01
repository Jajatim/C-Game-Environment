#include "includes.h"

void gameUpdate(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,MasterObject *pMasterObject) {
    //void gameUpdateBackground(); //Normally, doesn't need updating. Uncomment if needed
    gameUpdateRect(deltatime,pKeyboard,pMouse,pMasterObject->allObjRect);
    gameUpdateAnim(deltatime,pKeyboard,pMouse,pMasterObject->allObjAnim);
}


//void gameUpdateBackground() //Normally, doesn't need updating. Uncomment if needed


void gameUpdateRect(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,ObjRect allObjRect[OBJRECT_MAX]) {

    //TEMP - INITIALIZE DATA WHEN BALL IS OUTSIDE THE SCREEN
    if (allObjRect[OBJRECT_BALL].x<0 || allObjRect[OBJRECT_BALL].x>WINDOW_X) {
        gameInitRect(allObjRect);
    }
    //END TEMP


    // -- See enum in defines.h for details --
    //0 : left pad
    //1 : right pad
    //2 : ball


    //0 : left pad (zqsd)
    if (pKeyboard->Keyz==1) {
        allObjRect[OBJRECT_PAD_LEFT].y -= allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }
    if (pKeyboard->Keyq==1) {
        allObjRect[OBJRECT_PAD_LEFT].x -= allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }
    if (pKeyboard->Keys==1) {
        allObjRect[OBJRECT_PAD_LEFT].y += allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }
    if (pKeyboard->Keyd==1) {
        allObjRect[OBJRECT_PAD_LEFT].x += allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }


    //1 : right pad (arrow keys)
    if (pKeyboard->ArrowUp==1) {
        allObjRect[OBJRECT_PAD_RIGHT].y -= allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pKeyboard->ArrowLeft==1) {
        allObjRect[OBJRECT_PAD_RIGHT].x -= allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pKeyboard->ArrowDown==1) {
        allObjRect[OBJRECT_PAD_RIGHT].y += allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pKeyboard->ArrowRight==1) {
        allObjRect[OBJRECT_PAD_RIGHT].x += allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }

    /*
    //1 : right pad bis (mouse) - It works \o/
    if (pMouse->MouseX >= allObjRect[OBJRECT_PAD_RIGHT].x) {
        allObjRect[OBJRECT_PAD_RIGHT].x += allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    else {
        allObjRect[OBJRECT_PAD_RIGHT].x -= allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pMouse->MouseY >= allObjRect[OBJRECT_PAD_RIGHT].y) {
        allObjRect[OBJRECT_PAD_RIGHT].y += allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    else {
        allObjRect[OBJRECT_PAD_RIGHT].y -= allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }*/

    //2 : ball
    static float dirX=1; //X axis coefficient, here the ball goes straight on the X axis
    static float dirY=0; //Y axis coefficient, here the ball goes straight on the X axis
    //Note : Abolute values of x and y must add to make 1 in all cases (so the ball have a constant speed)

    //Collision ceiling
    if (allObjRect[OBJRECT_BALL].y<0) {
        dirY *= -1;
        allObjRect[OBJRECT_BALL].y=1;
    }

    //Collision floor
    if (allObjRect[OBJRECT_BALL].y+allObjRect[OBJRECT_BALL].h>WINDOW_Y) {
        dirY *= -1;
        allObjRect[OBJRECT_BALL].y=WINDOW_Y-allObjRect[OBJRECT_BALL].h-1;
    }

    //Check collision on the left pad (check starts 50px away from the pad)
    if (allObjRect[OBJRECT_BALL].x<allObjRect[OBJRECT_PAD_LEFT].x+50 && isColliding(allObjRect,2,0)==1) {

        //We check where the ball hits the pad (from 0 (top) to 1 (bottom)), we substract 0.5 so the ball will rebound accordingly
        dirY = ((allObjRect[OBJRECT_BALL].y + (allObjRect[OBJRECT_BALL].h/2)) - allObjRect[OBJRECT_PAD_LEFT].y) / allObjRect[OBJRECT_PAD_LEFT].h;
        dirY -= 0.5;

        //We recalculate X axis coefficient, who depends on Y axis coefficient so we stay at the same speed
        if (dirY<0) dirX = 1+dirY;
        else dirX = 1-dirY;
    }

    //Check collision on the right pad (check starts 50px away from the pad)
    if (allObjRect[OBJRECT_BALL].x>allObjRect[OBJRECT_PAD_RIGHT].x-50 && isColliding(allObjRect,2,1)==1) {

        //We check where the ball hits the pad (from 0 (top) to 1 (bottom)), we substract 0.5 so the ball will rebound accordingly
        dirY = ((allObjRect[OBJRECT_BALL].y + (allObjRect[OBJRECT_BALL].h/2)) - allObjRect[OBJRECT_PAD_RIGHT].y) / allObjRect[OBJRECT_PAD_RIGHT].h;
        dirY -= 0.5;

        //We recalculate X axis coefficient, who depends on Y axis coefficient so we stay at the same speed
        if (dirY<0) dirX = 1+dirY;
        else dirX = 1-dirY;

        //As we're recalculating the X axis coefficient, here we make the ball go left
        dirX *= -1;
    }

    //We move the ball, accordingly to the calculated coefficients and the speed
    allObjRect[OBJRECT_BALL].x += allObjRect[OBJRECT_BALL].speed*deltatime/1000 * dirX;
    allObjRect[OBJRECT_BALL].y += allObjRect[OBJRECT_BALL].speed*deltatime/1000 * dirY;
}


void gameUpdateAnim(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,ObjAnim allObjAnim[OBJANIM_MAX]) {
    //No update to do here yet
}


int isColliding(ObjRect allObjRect[OBJRECT_MAX], int a, int b) {
    //Pas de collision en haut ?
    if (allObjRect[a].x>allObjRect[b].x+allObjRect[b].w) return 0;

    //Pas de collision en bas ?
    if (allObjRect[a].x+allObjRect[a].w<allObjRect[b].x) return 0;

    //Pas de collision à gauche ?
    if (allObjRect[a].y>allObjRect[b].y+allObjRect[b].h) return 0;

    //Pas de collision à droite ?
    if (allObjRect[a].y+allObjRect[a].h<allObjRect[b].y) return 0;

    return 1;
}
