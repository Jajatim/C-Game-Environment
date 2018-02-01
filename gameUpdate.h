#ifndef GAMEUPDATE_H_INCLUDED
#define GAMEUPDATE_H_INCLUDED

#include "defines.h"

//Main update, calls others updates
void gameUpdate(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,MasterObject *pMasterObject);

//Sub updates
//void gameUpdateBackground(); //Normally, doesn't need updating. Uncomment if needed
void gameUpdateRect(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,ObjRect allObjRect[OBJRECT_MAX]);
void gameUpdateAnim(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,ObjAnim allObjAnim[OBJANIM_MAX]);

//Regular functions
int isColliding(ObjRect allObjRect[OBJRECT_MAX], int a, int b);

#endif // GAMEUPDATE_H_INCLUDED
