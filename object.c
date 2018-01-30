#include "includes.h"

void initMaster(MasterObject *pMasterObject) {
    initObjRect(pMasterObject->allObjRect);
    initObjAnim(pMasterObject->allObjAnim);
}

void initObjRect(ObjRect allObjRect[OBJRECT_MAX]) {
    int i;
    for (i=0;i<OBJRECT_MAX;i++) {
        allObjRect[i].x=0.0;
        allObjRect[i].y=0.0;
        allObjRect[i].w=0.0;
        allObjRect[i].h=0.0;
        allObjRect[i].speed=0.0;
    }
}

void initObjAnim(ObjAnim allObjAnim[OBJANIM_MAX]) {
    int i;
    for (i=0;i<OBJANIM_MAX;i++) {
        allObjAnim[i].x=0.0;
        allObjAnim[i].y=0.0;
        allObjAnim[i].w=0.0;
        allObjAnim[i].h=0.0;
        allObjAnim[i].speed=0.0;
    }
}
