#ifndef GAMEINIT_H_INCLUDED
#define GAMEINIT_H_INCLUDED

#include "defines.h"

//Main init - calls sub inits
void gameInit(MasterObject *pMasterObject);

//Sub inits - can be called independently
void gameInitRect(ObjRect allObjRect[OBJRECT_MAX]);
void gameInitAnim(ObjAnim allObjAnim[OBJANIM_MAX]);

#endif // GAMEINIT_H_INCLUDED
