#include "includes.h"


int main(int argc, char** argv)
{
    //Init de la SDL
    fInitSDL();

    //Création fenetre
    SDL_Window *pWindow = NULL;
    pWindow = fInitWindow(pWindow,"DAT GAME OMG",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_X,WINDOW_Y,SDL_WINDOW_SHOWN);

    //déclarations variables générales
    SDL_Surface* tpSurf[NB_MAX_SURF] = {NULL}; //tableau des pointeurs sur surfaces
    int exitRequest = 0; //Pour quitter la boucle du jeu (quitte tout !)
    Uint32 deltaTime = 0.0; //Gestion du timer

    //On crée la structure du clavier et son pointeur
    Keyboard KEYBOARD = {0};
    Keyboard *pKEYBOARD = &KEYBOARD;

    //Récup surface fenetre
    SDL_Surface *pWindowSurf = fNewWindowSurface(pWindow,pWindowSurf,tpSurf);

    //Tableau des objets
    anObject allObjects[NB_MAX_OBJ];
    initObject(allObjects);

    gameInit(allObjects);

    Uint32 renderTimer=0;
    Uint32 updateTimer=0;

    //Boucle de jeu infinie
    while(!exitRequest) {
        //GESTION TEMPS
        deltaTime = fTimer();


        //EVENT
        exitRequest = fEventManager(pKEYBOARD);


        //UPDATE
        updateTimer += deltaTime;
        if (updateTimer>=RENDER_TIMER) {
            gameUpdate(updateTimer,pKEYBOARD,allObjects);
            updateTimer=0;
        }


        //RENDER
        renderTimer += deltaTime;
        if (renderTimer>=RENDER_TIMER) {
            gameRender(pWindow,pWindowSurf,allObjects);
            renderTimer=0;
        }
        //SDL_UpdateWindowSurface(pWindow);
        SDL_Delay(1); // OR -> //_sleep(1);
    }

    //Free all surfaces
    fFreeAllSurfaces(tpSurf);

    //Destruction fenetre
    fDestroyWindow(pWindow);

    //Fermeture SDL
    fQuit();

    return EXIT_SUCCESS;
}
