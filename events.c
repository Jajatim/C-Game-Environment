#include "includes.h"

//int fEventManager(Keyboard *pKEYBOARD, SDL_Event *pEvent) {
int fEventManager(Keyboard *pKEYBOARD) {

    //On crée un event (et son pointeur pour éviter la copie) pour ne pas le recréer à chaque fois
    SDL_Event event;
    SDL_Event *pEvent = &event;

    SDL_PollEvent(pEvent);

    if ((*pEvent).type == SDL_QUIT) return 1;

    if (pEvent->type == SDL_KEYDOWN) {
        switch(pEvent->key.keysym.sym) {
            case SDLK_UP:
                pKEYBOARD->ArrowUp=1;
                break;
            case SDLK_DOWN:
                pKEYBOARD->ArrowDown=1;
                break;
            case SDLK_LEFT:
                pKEYBOARD->ArrowLeft=1;
                break;
            case SDLK_RIGHT:
                pKEYBOARD->ArrowRight=1;
                break;
            case SDLK_SPACE:
                pKEYBOARD->Space=1;
                break;
            case SDLK_z:
                pKEYBOARD->Keyz=1;
                break;
            case SDLK_q:
                pKEYBOARD->Keyq=1;
                break;
            case SDLK_s:
                pKEYBOARD->Keys=1;
                break;
            case SDLK_d:
                pKEYBOARD->Keyd=1;
                break;
        }
    }
    else if (pEvent->type == SDL_KEYUP) {
        switch(pEvent->key.keysym.sym) {
            case SDLK_UP:
                pKEYBOARD->ArrowUp=0;
                break;
            case SDLK_DOWN:
                pKEYBOARD->ArrowDown=0;
                break;
            case SDLK_LEFT:
                pKEYBOARD->ArrowLeft=0;
                break;
            case SDLK_RIGHT:
                pKEYBOARD->ArrowRight=0;
                break;
            case SDLK_SPACE:
                pKEYBOARD->Space=0;
                break;
            case SDLK_z:
                pKEYBOARD->Keyz=0;
                break;
            case SDLK_q:
                pKEYBOARD->Keyq=0;
                break;
            case SDLK_s:
                pKEYBOARD->Keys=0;
                break;
            case SDLK_d:
                pKEYBOARD->Keyd=0;
                break;
        }
    }

    return 0;
}
