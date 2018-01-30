#ifndef GAMERENDER_H_INCLUDED
#define GAMERENDER_H_INCLUDED

#include "defines.h"

void gameRender(SDL_Window *pWindow,SDL_Surface *pWindowSurf,MasterObject *pMasterObject);

void gameRenderRect(SDL_Window *pWindow,SDL_Surface *pWindowSurf,ObjRect allObjRect[OBJRECT_MAX]);
void gameRenderAnim(SDL_Window *pWindow,SDL_Surface *pWindowSurf,ObjAnim allObjAnim[OBJANIM_MAX]);

#endif // GAMERENDER_H_INCLUDED
