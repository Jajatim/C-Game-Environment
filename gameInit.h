#ifndef GAMEINIT_H_INCLUDED
#define GAMEINIT_H_INCLUDED

#include "defines.h"

void gameInit(MasterObject *pMasterObject);

void gameInitRect(ObjRect allObjRect[OBJRECT_MAX]);
void gameInitAnim(ObjAnim allObjAnim[OBJANIM_MAX]);

#endif // GAMEINIT_H_INCLUDED
