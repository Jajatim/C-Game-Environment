#ifndef GAMERENDER_H_INCLUDED
#define GAMERENDER_H_INCLUDED

#include "defines.h"

//Main render, calls others renders
void gameRender(SDL_Window *pWindow,SDL_Surface *pWindowSurf,MasterObject *pMasterObject);

//Sub renders
void gameRenderRect(SDL_Window *pWindow,SDL_Surface *pWindowSurf,ObjRect allObjRect[OBJRECT_MAX]);
void gameRenderAnim(SDL_Window *pWindow,SDL_Surface *pWindowSurf,ObjAnim allObjAnim[OBJANIM_MAX]);

#endif // GAMERENDER_H_INCLUDED
