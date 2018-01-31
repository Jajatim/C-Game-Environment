#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "defines.h"

//Main creation - calls sub creations (should be called createMaster really... I'll get to that some day !)
void initMaster(MasterObject *pMasterObject);

//Sub creations (should be called createXXXXXX really... I'll get to that some day !)
void initObjRect(ObjRect allObjRect[OBJRECT_MAX]);
void initObjAnim(ObjAnim allObjAnim[OBJANIM_MAX]);


#endif // OBJECT_H_INCLUDED
