#include "includes.h"

int fEventManager(Keyboard *pKeyboard, Mouse *pMouse) {

    //We need an event (the pointer is quite useless, but meh...)
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        //First of all, we test if the user want to exit the soft.
        if (event.type == SDL_QUIT) return 1; //Returns true to the "exitGame" variable

        //KEYBOARD EVENTS
        //Updates keyboard when pressing a key
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pKeyboard->ArrowUp=1;
                    break;
                case SDLK_DOWN:
                    pKeyboard->ArrowDown=1;
                    break;
                case SDLK_LEFT:
                    pKeyboard->ArrowLeft=1;
                    break;
                case SDLK_RIGHT:
                    pKeyboard->ArrowRight=1;
                    break;
                case SDLK_SPACE:
                    pKeyboard->Space=1;
                    break;
                case SDLK_z:
                    pKeyboard->Keyz=1;
                    break;
                case SDLK_q:
                    pKeyboard->Keyq=1;
                    break;
                case SDLK_s:
                    pKeyboard->Keys=1;
                    break;
                case SDLK_d:
                    pKeyboard->Keyd=1;
                    break;
            }
        }
        //Updates keyboard when releasing a key
        else if (event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pKeyboard->ArrowUp=0;
                    break;
                case SDLK_DOWN:
                    pKeyboard->ArrowDown=0;
                    break;
                case SDLK_LEFT:
                    pKeyboard->ArrowLeft=0;
                    break;
                case SDLK_RIGHT:
                    pKeyboard->ArrowRight=0;
                    break;
                case SDLK_SPACE:
                    pKeyboard->Space=0;
                    break;
                case SDLK_z:
                    pKeyboard->Keyz=0;
                    break;
                case SDLK_q:
                    pKeyboard->Keyq=0;
                    break;
                case SDLK_s:
                    pKeyboard->Keys=0;
                    break;
                case SDLK_d:
                    pKeyboard->Keyd=0;
                    break;
            }
        }

        //MOUSE EVENTS - 3 parts : Clicking, Moving and Mousewheeling
        //Additional : Lots more to do here, like handling double click and where the click was clicked, etc...

        //Part 1 : Clicking
        //Updates mouse when clicking a button
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pMouse->MouseLeftClic=1;
                    break;
                case SDL_BUTTON_RIGHT:
                    pMouse->MouseRightClic=1;
                    break;
            }
        }
        //Updates mouse when releasing a button
        else if (event.type == SDL_MOUSEBUTTONUP) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pMouse->MouseLeftClic=0;
                    break;
                case SDL_BUTTON_RIGHT:
                    pMouse->MouseRightClic=0;
                    break;
            }
        }

        //Part 2 : Moving
        if (event.type == SDL_MOUSEMOTION) {
            pMouse->MouseX=event.motion.x;
            pMouse->MouseY=event.motion.y;
        }

        /* A bit harder than it looks :D. We'll see when we need to handle the mighty mouse wheel.
        //Part 3 : Mousewheeling
        if (event.type == SDL_MOUSEWHEEL) {
            switch(event.wheel.y) {
                case 1: //Wheeling up
                    pMouse->MouseWheelUp=1;
                    break;
                case -1: //Wheeling down
                    pMouse->MouseWheelDown=1;
                    break;
            }
        }
        */

        //OTHER EVENTS ?
        // To be continued...
    }

    return 0; //Returns false to the "exitGame" variable
}
