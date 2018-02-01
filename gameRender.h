#ifndef GAMERENDER_H_INCLUDED
#define GAMERENDER_H_INCLUDED

#include "defines.h"

//Main render, calls others renders
void gameRender(Window *pWindowStruct,MasterObject *pMasterObject);

//Sub renders
void gameRenderBackground(SDL_Renderer *pRenderer,ObjBackground allObjBackground[OBJBACKGROUND_MAX]);
void gameRenderRect(SDL_Renderer *pRenderer,ObjRect allObjRect[OBJRECT_MAX]);
void gameRenderAnim(SDL_Renderer *pRenderer,ObjAnim allObjAnim[OBJANIM_MAX]);

#endif // GAMERENDER_H_INCLUDED
