#ifndef GAMEINIT_H_INCLUDED
#define GAMEINIT_H_INCLUDED

#include "defines.h"

//Main init - calls sub inits
void gameInit(Window *pWindowStruct,MasterObject *pMasterObject);

//Sub inits - can be called independently
void gameInitBackground(SDL_Renderer *pRenderer,ObjBackground allObjBackground[OBJBACKGROUND_MAX]);
void gameInitRect(ObjRect allObjRect[OBJRECT_MAX]);
void gameInitAnim(SDL_Renderer *pRenderer,ObjAnim allObjAnim[OBJANIM_MAX]);

#endif // GAMEINIT_H_INCLUDED
