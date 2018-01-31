#include "includes.h"

//Note for build warnings, the pointers are initialized in the creating functions. You can safely ignore theses errors.

int main(int argc, char** argv)
{
    //PART 1 - BASIC INITIALIZATION
    //SDL Initialization
    fInitSDL();

    //Main window creation
    SDL_Window *pWindow = fInitWindow(pWindow,"DAT GAME OMG",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_X,WINDOW_Y,SDL_WINDOW_SHOWN);


    //PART 2 - GENERAL PURPOSE VARIABLES
    //general variables
    SDL_Surface* tpSurf[NB_MAX_SURF] = {NULL}; //surface's pointers table. Used to free everyone at once when exiting.
    int exitRequest = 0; //To break from the game loop
    Uint32 deltaTime = 0.0; //for timer handling

    //Creating the keyboard map
    Keyboard KEYBOARD = {0};
    Keyboard *pKEYBOARD = &KEYBOARD;

    //Creating the window surface
    SDL_Surface *pWindowSurf = fNewWindowSurface(pWindow,pWindowSurf,tpSurf);

    //On crée la structure master (qui contient un tableau de chaque structure)
    MasterObject aMasterObject;
    MasterObject *pMasterObject = &aMasterObject;
    initMaster(pMasterObject);

    //Creating the timers
    Uint32 renderTimer=RENDER_TIMER;
    Uint32 updateTimer=UPDATE_TIMER;


    //PART 3 - GAME INDEED
    //Game starts
    gameInit(pMasterObject);

    //Here comes the game loop
    while(!exitRequest) {
        //TIME HANDLING
        deltaTime = fTimer();


        //EVENT HANDLING
        exitRequest = fEventManager(pKEYBOARD);


        //UPDATE HANDLING
        updateTimer += deltaTime;
        if (updateTimer>=UPDATE_TIMER) {
            gameUpdate(updateTimer,pKEYBOARD,pMasterObject);
            updateTimer=0;
        }


        //RENDER HANDLING
        renderTimer += deltaTime;
        if (renderTimer>=RENDER_TIMER) {
            gameRender(pWindow,pWindowSurf,pMasterObject);
            renderTimer=0;
        }
        SDL_Delay(1); // OR -> //_sleep(1);
    }


    //PART 4 - WE ALL GOT TO DIE SOMEDAY
    //Free all created surfaces
    fFreeAllSurfaces(tpSurf);

    //Destroying the window
    fDestroyWindow(pWindow);

    //Uninitializing SDL
    fQuit();

    return EXIT_SUCCESS;
}
