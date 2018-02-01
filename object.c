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
        allObjAnim[i].x=0.0;
        allObjAnim[i].y=0.0;
        allObjAnim[i].w=0.0;
        allObjAnim[i].h=0.0;
        allObjAnim[i].speed=0.0;
    }
}
