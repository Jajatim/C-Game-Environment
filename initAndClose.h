#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "defines.h"

//Initialisation (SDL, windows, surfaces, etc...)
void fInitSDL();
Window* fInitWindow(Window *pWindowStruct, const char windowName[50], int x, int y, int w, int h, Uint32 flags);

//General creations
void addSurfToDelTable(SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]);
SDL_Surface* fNewBMPSurface(SDL_Surface *pSurfAdr, const char *filePath, SDL_Surface* tpSurf[NB_MAX_SURF]);
SDL_Texture* fNewTextureFromBMP(SDL_Renderer *pRenderer,const char *filePath);

//Functions needed to close the software
void fFreeAllSurfaces(SDL_Surface* tpSurf[NB_MAX_SURF]);
void fDestroyWindow(Window *pWindowStruct);
void fQuit();

#endif // INIT_H_INCLUDED
