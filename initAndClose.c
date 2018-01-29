#include "includes.h"

SDL_Window *pWindowAdrGeneral = NULL;

//Initialisation simple
void fInitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"�chec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
}

//Cr�ation de la fen�tre
SDL_Window* fInitWindow(SDL_Window *pWindowAdr, const char windowName[50], int x, int y, int w, int h, Uint32 flags) {
    pWindowAdr = NULL;
    pWindowAdr = SDL_CreateWindow(windowName,x,y,w,h,flags);

    if(pWindowAdr==NULL) {
        fprintf(stderr,"Erreur de cr�ation de la fen�tre: %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    pWindowAdrGeneral = pWindowAdr;

    return pWindowAdr;
}

//Ajout d'une surface au tableau des adresses de surfaces
void addSurfToDelTable(SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]) {
    static int current_id=0;
    tpSurf[current_id]=pSurfAdr;
    current_id++;
}

//Nouvelle surface de fenetre (on stocke son pointeur dans notre tableau de pointeurs pour pouvoir les lib�rer � la fin)
SDL_Surface* fNewWindowSurface(SDL_Window *pWindowAdr, SDL_Surface *pSurfAdr, SDL_Surface* tpSurf[NB_MAX_SURF]) {
    pSurfAdr = NULL;
    pSurfAdr = SDL_GetWindowSurface( pWindowAdr );
    if(pSurfAdr==NULL) {
        fprintf(stderr,"Erreur de cr�ation de surface : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
    addSurfToDelTable(pSurfAdr,tpSurf);

    return pSurfAdr;
}

//Nouvelle surface (on stocke son pointeur dans notre tableau de pointeurs pour pouvoir les lib�rer � la fin)
SDL_Surface* fNewBMPSurface(SDL_Surface *pSurfAdr, const char *filePath, SDL_Surface* tpSurf[NB_MAX_SURF]) {
    pSurfAdr = NULL;
    pSurfAdr = SDL_LoadBMP(filePath);
    if(pSurfAdr==NULL) {
        fprintf(stderr,"Erreur de cr�ation de surface : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    //SDL_ConvertSurface

    addSurfToDelTable(pSurfAdr,tpSurf);

    return pSurfAdr;
}

//Lib�ration de toutes les surfaces cr��es
void fFreeAllSurfaces(SDL_Surface* tpSurf[NB_MAX_SURF]) {
    int i=0;
    for (i=0;i<NB_MAX_SURF;i++) {
        if (tpSurf[i]!=NULL) {
            SDL_FreeSurface(tpSurf[i]);
            tpSurf[i]=NULL;
        }
    }
}

//Destruction de la fenetre
void fDestroyWindow(SDL_Window *pWindowAdr){
    SDL_DestroyWindow(pWindowAdr);
}

//Extinction de la SDL
void fQuit() {
    SDL_Quit();
}
