#include "includes.h"

void gameInit(Window *pWindowStruct,MasterObject *pMasterObject) {
    gameInitBackground(pWindowStruct->pRenderer,pMasterObject->allObjBackground);
    gameInitRect(pMasterObject->allObjRect);
    gameInitAnim(pMasterObject->allObjAnim);
}


void gameInitBackground(SDL_Renderer *pRenderer,ObjBackground allObjBackground[OBJBACKGROUND_MAX]){
    //allObjBackground[OBJBACKGROUND_MAIN].pBGTexture = fNewTextureFromBMP(pRenderer,"aaa.bmp"); //Replace "aaa.bmp" with a bmp file of yours
}


void gameInitRect(ObjRect allObjRect[OBJRECT_MAX]) {
    //See enumeration in "defines.h" for details

    //0 : left pad
    allObjRect[OBJRECT_PAD_LEFT].x = 20;
    allObjRect[OBJRECT_PAD_LEFT].y = WINDOW_Y/2-100/2;
    allObjRect[OBJRECT_PAD_LEFT].w = 20;
    allObjRect[OBJRECT_PAD_LEFT].h = 100;
    allObjRect[OBJRECT_PAD_LEFT].speed = 300;
    allObjRect[OBJRECT_PAD_LEFT].color_r = 255;
    allObjRect[OBJRECT_PAD_LEFT].color_g = 50;
    allObjRect[OBJRECT_PAD_LEFT].color_b = 50;
    //allObjRect[OBJRECT_PAD_LEFT].color_a //We keep the default opaque

    //1 : right pad
    allObjRect[OBJRECT_PAD_RIGHT].x = WINDOW_X-20-20;
    allObjRect[OBJRECT_PAD_RIGHT].y = WINDOW_Y/2-100/2;
    allObjRect[OBJRECT_PAD_RIGHT].w = 20;
    allObjRect[OBJRECT_PAD_RIGHT].h = 100;
    allObjRect[OBJRECT_PAD_RIGHT].speed = 300;
    allObjRect[OBJRECT_PAD_RIGHT].color_r = 50;
    allObjRect[OBJRECT_PAD_RIGHT].color_g = 50;
    allObjRect[OBJRECT_PAD_RIGHT].color_b = 255;
    //allObjRect[OBJRECT_PAD_RIGHT].color_a //We keep the default opaque

    //2 : Ball
    allObjRect[OBJRECT_BALL].x = WINDOW_X/2-20/2;
    allObjRect[OBJRECT_BALL].y = WINDOW_Y/2-20/2;
    allObjRect[OBJRECT_BALL].w = 20;
    allObjRect[OBJRECT_BALL].h = 20;
    allObjRect[OBJRECT_BALL].speed = 750;
    allObjRect[OBJRECT_BALL].color_r = 255;
    allObjRect[OBJRECT_BALL].color_g = 255;
    allObjRect[OBJRECT_BALL].color_b = 50;
    //allObjRect[OBJRECT_BALL].color_a //We keep the default opaque
}


void gameInitAnim(ObjAnim allObjAnim[OBJANIM_MAX]) {
    //See enumeration in "defines.h" for details

    /*
    allObjAnim[OBJANIM_ONE].x = 0;
    allObjAnim[OBJANIM_ONE].y = 0;
    allObjAnim[OBJANIM_ONE].w = WINDOW_X;
    allObjAnim[OBJANIM_ONE].h = WINDOW_Y;
    allObjAnim[OBJANIM_ONE].speed = 0;
    */
}
