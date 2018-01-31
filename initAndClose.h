#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "defines.h"

//Initialisation (SDL, windows, surfaces, etc...)
void fInitSDL();
SDL_Window* fInitWindow(SDL_Window *pWindowAdr, const char windowName[50], int x, int y, int w, int h, Uint32 flags);
void addSurfToDelTable(SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]);
SDL_Surface* fNewWindowSurface(SDL_Window *pWindowAdr, SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]);
SDL_Surface* fNewBMPSurface(SDL_Surface *pSurfAdr, const char *filePath, SDL_Surface* tpSurf[NB_MAX_SURF]);

//Functions needed to close the software
void fFreeAllSurfaces(SDL_Surface* tpSurf[NB_MAX_SURF]);
void fDestroyWindow(SDL_Window *pWindowAdr);
void fQuit();

#endif // INIT_H_INCLUDED
