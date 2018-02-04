#ifndef GAMERENDER_H_INCLUDED
#define GAMERENDER_H_INCLUDED

#include "defines.h"

//Main render, calls others renders
void gameRender(Window *pWindowStruct,MasterObject *pMasterObject,MapCurrent *pMapCurrent);

//Sub renders
void gameRenderBackground(SDL_Renderer *pRenderer,ObjBackground allObjBackground[OBJBACKGROUND_MAX]);
void gameRenderMainChar(SDL_Renderer *pRenderer,MainChar *pMainChar,MasterObject *pMasterObject);
void gameRenderRect(SDL_Renderer *pRenderer,ObjRect allObjRect[OBJRECT_MAX]);
void gameRenderAnim(SDL_Renderer *pRenderer,ObjAnim allObjAnim[OBJANIM_MAX]);

void gameRenderMap(SDL_Renderer *pRenderer,MapCurrent *pMapCurrent,MasterObject *pMasterObject);
#endif // GAMERENDER_H_INCLUDED
