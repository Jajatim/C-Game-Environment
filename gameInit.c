#include "includes.h"

void gameInit(MasterObject *pMasterObject) {
    gameInitRect(pMasterObject->allObjRect);
    gameInitAnim(pMasterObject->allObjAnim);
}


void gameInitRect(ObjRect allObjRect[OBJRECT_MAX]) {
    //Voir l'enumeration dans "defines.h" pour voir les correspondances

    //0 : pad gauche
    allObjRect[OBJRECT_PAD_LEFT].x = 20;
    allObjRect[OBJRECT_PAD_LEFT].y = WINDOW_Y/2-100/2;
    allObjRect[OBJRECT_PAD_LEFT].w = 20;
    allObjRect[OBJRECT_PAD_LEFT].h = 100;
    allObjRect[OBJRECT_PAD_LEFT].speed = 300;

    //1 : pad droite
    allObjRect[OBJRECT_PAD_RIGHT].x = WINDOW_X-20-20;
    allObjRect[OBJRECT_PAD_RIGHT].y = WINDOW_Y/2-100/2;
    allObjRect[OBJRECT_PAD_RIGHT].w = 20;
    allObjRect[OBJRECT_PAD_RIGHT].h = 100;
    allObjRect[OBJRECT_PAD_RIGHT].speed = 300;

    //2 : Balle
    allObjRect[OBJRECT_BALL].x = WINDOW_X/2-20/2;
    allObjRect[OBJRECT_BALL].y = WINDOW_Y/2-20/2;
    allObjRect[OBJRECT_BALL].w = 20;
    allObjRect[OBJRECT_BALL].h = 20;
    allObjRect[OBJRECT_BALL].speed = 750;
}


void gameInitAnim(ObjAnim allObjAnim[OBJANIM_MAX]) {
    allObjAnim[OBJANIM_BACKGROUND].x = 0;
    allObjAnim[OBJANIM_BACKGROUND].y = 0;
    allObjAnim[OBJANIM_BACKGROUND].w = WINDOW_X;
    allObjAnim[OBJANIM_BACKGROUND].h = WINDOW_Y;
    allObjAnim[OBJANIM_BACKGROUND].speed = 0;
}
