#ifndef GAMEUPDATE_H_INCLUDED
#define GAMEUPDATE_H_INCLUDED

#include "defines.h"

void gameUpdate(Uint32 deltatime,Keyboard *pKEYBOARD,anObject allObject[NB_MAX_OBJ]);
int isColliding(anObject allObject[NB_MAX_OBJ], int a, int b);

#endif // GAMEUPDATE_H_INCLUDED
