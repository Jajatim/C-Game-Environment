#include "includes.h"

void createMaster(MasterObject *pMasterObject) {
    createObjBackground(pMasterObject->allObjBackground);
    createObjRect(pMasterObject->allObjRect);
    createObjAnim(pMasterObject->allObjAnim);
}

void createObjBackground(ObjBackground allObjBackground[OBJBACKGROUND_MAX]) {
    int i;
    for (i=0;i<OBJBACKGROUND_MAX;i++) {
        allObjBackground[i].pBGTexture=NULL;
    }
}

void createObjRect(ObjRect allObjRect[OBJRECT_MAX]) {
    int i;
    for (i=0;i<OBJRECT_MAX;i++) {
        allObjRect[i].x=0.0;
        allObjRect[i].y=0.0;
        allObjRect[i].w=0.0;
        allObjRect[i].h=0.0;
        allObjRect[i].speed=0.0;
        allObjRect[i].color_r=255; //White by default
        allObjRect[i].color_g=255; //White by default
        allObjRect[i].color_b=255; //White by default
        allObjRect[i].color_a=255; //Opaque by default
    }
}

void createObjAnim(ObjAnim allObjAnim[OBJANIM_MAX]) {
    int i;
    for (i=0;i<OBJANIM_MAX;i++) {
        allObjAnim[i].inGamePos.x=0;
        allObjAnim[i].inGamePos.y=0;
        allObjAnim[i].inGamePos.w=0;
        allObjAnim[i].inGamePos.h=0;
        allObjAnim[i].currentSpritePos.x=0;
        allObjAnim[i].currentSpritePos.y=0;
        allObjAnim[i].currentSpritePos.w=0;
        allObjAnim[i].currentSpritePos.h=0;
        allObjAnim[i].speed=0.0;
        allObjAnim[i].pTexture=NULL;

        allObjAnim[i].animType = 1; //Need enumeration, or we'll get lost later on... Here : 1=idle_right 2=idle_left 3=move_right 4=move_left
        allObjAnim[i].spriteWidth = 0;
        allObjAnim[i].spriteHeight = 0;
        allObjAnim[i].spriteCurrent = 1;

        allObjAnim[i].spriteMax = 0;
        allObjAnim[i].framesPerSprite = 0;
        allObjAnim[i].framesTimer = 0;

        allObjAnim[i].color_r = -1;
        allObjAnim[i].color_g = -1;
        allObjAnim[i].color_b = -1;
    }
}
