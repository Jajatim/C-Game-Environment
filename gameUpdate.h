#ifndef GAMEUPDATE_H_INCLUDED
#define GAMEUPDATE_H_INCLUDED

#include "defines.h"

//Main update, calls others updates
void gameUpdate(Uint32 deltatime,Keyboard *pKEYBOARD,MasterObject *pMasterObject);

//Sub updates
void gameUpdateRect(Uint32 deltatime,Keyboard *pKEYBOARD,ObjRect allObjRect[OBJRECT_MAX]);
void gameUpdateAnim(Uint32 deltatime,Keyboard *pKEYBOARD,ObjAnim allObjAnim[OBJANIM_MAX]);

//Regular functions
int isColliding(ObjRect allObjRect[OBJRECT_MAX], int a, int b);

#endif // GAMEUPDATE_H_INCLUDED
