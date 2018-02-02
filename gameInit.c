#include "includes.h"

void gameInit(Window *pWindowStruct,MasterObject *pMasterObject) {
    gameInitBackground(pWindowStruct->pRenderer,pMasterObject->allObjBackground);
    gameInitRect(pMasterObject->allObjRect);
    gameInitAnim(pWindowStruct->pRenderer,pMasterObject->allObjAnim);
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


void gameInitAnim(SDL_Renderer *pRenderer,ObjAnim allObjAnim[OBJANIM_MAX]) {
    //See enumeration in "defines.h" for details

    //Character appears in the centre of the screen
    allObjAnim[OBJANIM_MAINCHAR].inGamePos.w = 30;
    allObjAnim[OBJANIM_MAINCHAR].inGamePos.h = 50;
    allObjAnim[OBJANIM_MAINCHAR].inGamePos.x = WINDOW_X/2-allObjAnim[OBJANIM_MAINCHAR].inGamePos.w/2;
    allObjAnim[OBJANIM_MAINCHAR].inGamePos.y = WINDOW_Y/2-allObjAnim[OBJANIM_MAINCHAR].inGamePos.h/2;

    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.x = 180;
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.y = 54;
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.w = 24;
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.h = 38;

    allObjAnim[OBJANIM_MAINCHAR].speed = 300;
    allObjAnim[OBJANIM_MAINCHAR].pTexture = fNewTextureFromBMP(pRenderer,"Stolen_Yoshi.bmp");

    allObjAnim[OBJANIM_MAINCHAR].animType = 1; //Need enumeration, or we'll get lost later on... Here : 1=idle_right 2=idle_left 3=move_right 4=move_left
    allObjAnim[OBJANIM_MAINCHAR].spriteWidth = 30;
    allObjAnim[OBJANIM_MAINCHAR].spriteHeight = 40;
    allObjAnim[OBJANIM_MAINCHAR].spriteCurrent = 1;

    allObjAnim[OBJANIM_MAINCHAR].spriteMax = 6;
    allObjAnim[OBJANIM_MAINCHAR].framesPerSprite = 25;
    /*
    allObjAnim[OBJANIM_MAINCHAR].color_r = -1;
    allObjAnim[OBJANIM_MAINCHAR].color_g = -1;
    allObjAnim[OBJANIM_MAINCHAR].color_b = -1;
    */
}
