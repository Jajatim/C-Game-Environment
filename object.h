#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "defines.h"

//Main creation - calls sub creations
void createMaster(MasterObject *pMasterObject);

//Sub creations
void createObjBackground(ObjBackground allObjBackground[OBJBACKGROUND_MAX]);
void createObjRect(ObjRect allObjRect[OBJRECT_MAX]);
void createObjAnim(ObjAnim allObjAnim[OBJANIM_MAX]);


#endif // OBJECT_H_INCLUDED
