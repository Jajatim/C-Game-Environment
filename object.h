#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "defines.h"

//Main creation - calls sub creations
void createMaster(MasterObject *pMasterObject);

//Sub creations
void createMainChar(MainChar *pMainChar);
void createObjBackground(ObjBackground allObjBackground[OBJBACKGROUND_MAX]);
void createObjRect(ObjRect allObjRect[OBJRECT_MAX]);
void createObjAnim(ObjAnim allObjAnim[OBJANIM_MAX]);

//Map creation
void createMapGlobal(SDL_Renderer *pRenderer,MapCurrent *pMapCurrent,MapGlobal *pMapGlobal,MapChunk *pMapChunk);
void createMapChunk(SDL_Renderer *pRenderer,MapChunk *pMapChunk);


#endif // OBJECT_H_INCLUDED
