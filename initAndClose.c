#include "includes.h"

//Initialization SDL
void fInitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0 ) {
        fprintf(stdout,"SDL initialization failed. (%s)\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
}


//Main window creation, and it's renderer
Window* fInitWindow(Window *pWindowStruct, const char windowName[50], int x, int y, int w, int h, Uint32 flags) {
    //Creating the window
    pWindowStruct->pWindow = NULL;
    pWindowStruct->pWindow = SDL_CreateWindow(windowName,x,y,w,h,flags);
    if(pWindowStruct->pWindow==NULL) {
        fprintf(stderr,"Couldn't create the window: %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    //Creating the renderer
    pWindowStruct->pRenderer = NULL;
    pWindowStruct->pRenderer = SDL_CreateRenderer(pWindowStruct->pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(pWindowStruct->pRenderer==NULL) {
        fprintf(stderr,"Couldn't create the renderer: %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    return pWindowStruct;
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
        fprintf(stderr,"Couldn't create the surface : %s\n",SDL_GetError());
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
        fprintf(stderr,"Couldn't create the surface from .bmp file : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }
    addSurfToDelTable(pSurfAdr,tpSurf);

    return pSurfAdr;
}

//Creating a texture from a surface
SDL_Texture* fNewTextureFromBMP(SDL_Renderer *pRenderer,const char *filePath) {
    //Creating a temporary surface to load the file
    SDL_Surface *pSurfTemp = NULL;
    pSurfTemp = SDL_LoadBMP(filePath);
    if(pSurfTemp==NULL) {
        fprintf(stderr,"Couldn't create the surface from .bmp file : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    //We load the surface onto the texture
    SDL_Texture *pTexture = NULL;
    SDL_SetColorKey(pSurfTemp, SDL_TRUE,SDL_MapRGB( pSurfTemp->format, 255, 0, 255));
    pTexture = SDL_CreateTextureFromSurface(pRenderer,pSurfTemp);
    if(pTexture==NULL) {
        fprintf(stderr,"Couldn't create the texture from the surface : %s\n",SDL_GetError());
        system("pause");
        exit(EXIT_FAILURE);
    }

    //We don't need the surface anymore, let's kill it (with fire)
    SDL_FreeSurface(pSurfTemp);

    //We return the texture
    return pTexture;
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
void fDestroyWindow(Window *pWindowStruct){
    SDL_DestroyRenderer(pWindowStruct->pRenderer);
    SDL_DestroyWindow(pWindowStruct->pWindow);
}

//Well, there was no need for that function, was it?...
void fQuit() {
    SDL_Quit();
}
