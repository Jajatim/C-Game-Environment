#include "includes.h"

//Note for build warnings, the pointers are initialized in the creating functions (initAndClose.c). You can safely ignore theses errors.

int main(int argc, char** argv)
{
    //***********************************
    //** PART 1 - BASIC INITIALIZATION **
    //***********************************

    //SDL Initialization
    fInitSDL();

    //Main window creation and it's associated renderer
    Window *pWindowStruct = fInitWindow(pWindowStruct,"DAT GAME OMG",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_X,WINDOW_Y,SDL_WINDOW_SHOWN);



    //****************************************
    //** PART 2 - GENERAL PURPOSE VARIABLES **
    //****************************************

    //General variables
    SDL_Surface* tpSurf[NB_MAX_SURF] = {NULL}; //surface's pointers table. Used to free everyone at once when exiting. Might be useless with textures though...
    int exitRequest = 0; //To break from the game loop
    Uint32 deltaTime = 0.0; //for timer handling

    //Creating the keyboard structure
    Keyboard aKeyboard = {0};
    Keyboard *pKeyboard = &aKeyboard;

    //Creating the mouse structure
    Mouse aMouse = {0};
    Mouse *pMouse = &aMouse;

    //Creating the MasterObject (which contains a table of every other object)
    MasterObject aMasterObject;
    MasterObject *pMasterObject = &aMasterObject;
    createMaster(pMasterObject);

    //Creating the timers - Initialized at the wanted value so the first loop will do the actions it's supposed to.
    Uint32 renderTimer=RENDER_TIMER;
    Uint32 updateTimer=UPDATE_TIMER;



    //**************************
    //** PART 3 - GAME INDEED **
    //**************************

    //Game starts, we initialize all objects to their starting state
    gameInit(pWindowStruct,pMasterObject);

    //Here comes the game loop
    while(!exitRequest) {
        //TIME HANDLING
        deltaTime = fTimer();


        //EVENT HANDLING
        exitRequest = fEventManager(pKeyboard,pMouse);


        //UPDATE HANDLING
        updateTimer += deltaTime;
        if (updateTimer>=UPDATE_TIMER) {
            gameUpdate(updateTimer,pKeyboard,pMouse,pMasterObject);
            updateTimer=0;
        }


        //RENDER HANDLING
        renderTimer += deltaTime;
        if (renderTimer>=RENDER_TIMER) {
            gameRender(pWindowStruct,pMasterObject);
            renderTimer=0;
        }
        SDL_Delay(1); // OR -> //_sleep(1);
    }



    //****************************************
    //** PART 4 - WE ALL GOT TO DIE SOMEDAY **
    //****************************************

    //Free all created surfaces. Might be useless with textures though...
    fFreeAllSurfaces(tpSurf);

    //Destroying the window and it's associated renderer
    fDestroyWindow(pWindowStruct);

    //Uninitializing SDL
    fQuit();

    return EXIT_SUCCESS;
}
