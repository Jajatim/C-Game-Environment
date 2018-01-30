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

    //On crée la structure master (qui contient un tableau de chaque structure)
    MasterObject aMasterObject;
    MasterObject *pMasterObject = &aMasterObject;
    initMaster(pMasterObject);

    //Déclaration des timers
    Uint32 renderTimer=RENDER_TIMER;
    Uint32 updateTimer=UPDATE_TIMER;


    //Début du jeu
    gameInit(pMasterObject);

    //Boucle de jeu
    while(!exitRequest) {
        //GESTION TEMPS
        deltaTime = fTimer();


        //EVENT
        exitRequest = fEventManager(pKEYBOARD);


        //UPDATE
        updateTimer += deltaTime;
        if (updateTimer>=UPDATE_TIMER) {
            gameUpdate(updateTimer,pKEYBOARD,pMasterObject);
            updateTimer=0;
        }


        //RENDER
        renderTimer += deltaTime;
        if (renderTimer>=RENDER_TIMER) {
            gameRender(pWindow,pWindowSurf,pMasterObject);
            renderTimer=0;
        }
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
