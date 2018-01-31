#include "includes.h"

//Initialization SDL
void fInitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
}

//Main window creation
SDL_Window* fInitWindow(SDL_Window *pWindowAdr, const char windowName[50], int x, int y, int w, int h, Uint32 flags) {
    pWindowAdr = NULL;
    pWindowAdr = SDL_CreateWindow(windowName,x,y,w,h,flags);

    if(pWindowAdr==NULL) {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    return pWindowAdr;
}

//Adding a surface pointer to the surface table. This table is used to free every surface when exiting application.
void addSurfToDelTable(SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]) {
    static int current_id=0;
    tpSurf[current_id]=pSurfAdr;
    current_id++;
}

//Creating a window surface
SDL_Surface* fNewWindowSurface(SDL_Window *pWindowAdr, SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]) {
    pSurfAdr = NULL;
    pSurfAdr = SDL_GetWindowSurface( pWindowAdr );
    if(pSurfAdr==NULL) {
        fprintf(stderr,"Erreur de création de surface : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
    //addSurfToDelTable(pSurfAdr,tpSurf); //No need to keep this pointer in our table as it's not a real surface

    return pSurfAdr;
}

//Creating a surface from a BMP file (pointer is added in the surface table so we can free it automatically when game exits)
SDL_Surface* fNewBMPSurface(SDL_Surface *pSurfAdr, const char *filePath, SDL_Surface* tpSurf[NB_MAX_SURF]) {
    pSurfAdr = NULL;
    pSurfAdr = SDL_LoadBMP(filePath);
    if(pSurfAdr==NULL) {
        fprintf(stderr,"Erreur de création de surface : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
    addSurfToDelTable(pSurfAdr,tpSurf);

    return pSurfAdr;
}

//Going through all surface pointers we've created so far, and freeing them (GOOD LUCK GUYS, HAVE FUN BEING FREE !!)
void fFreeAllSurfaces(SDL_Surface* tpSurf[NB_MAX_SURF]) {
    int i=0;
    for (i=0;i<NB_MAX_SURF;i++) {
        if (tpSurf[i]!=NULL) {
            SDL_FreeSurface(tpSurf[i]);
            tpSurf[i]=NULL;
        }
    }
}

//Destroying the main window
void fDestroyWindow(SDL_Window *pWindowAdr){
    SDL_DestroyWindow(pWindowAdr);
}

//Well, there was no need for that function, was it?...
void fQuit() {
    SDL_Quit();
}
