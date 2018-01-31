#include "includes.h"


// NEED REWORK TO WORK WITH RENDERERS !

void gameRender(SDL_Window *pWindow,SDL_Surface *pWindowSurf,MasterObject *pMasterObject) {

    //Screen erase (well, covers it in black...)
    SDL_FillRect(pWindowSurf,NULL,SDL_MapRGB(pWindowSurf->format,0,0,0));

    //Calls sub renders
    gameRenderAnim(pWindow,pWindowSurf,pMasterObject->allObjAnim);
    gameRenderRect(pWindow,pWindowSurf,pMasterObject->allObjRect);

    /*
    PROBLEM : Can't choose rendering order...
        -> for example : here anim is called first cause it's some kind of background, if called second we wouldn't see the pads and the ball

    SOLUTION 1 : "Buffering" all objects in smaller MasterObjects according to a "turn order" (member of structs, user defined) maybe?
        -> Sounds slow but might work.
    SOLUTION 2 : Creating objects and members in the right order maybe ?.
        -> Sounds like lots of work for starters, and awful maintenance. We wouldn't be able to have exceptions as well...
    */

    SDL_UpdateWindowSurface(pWindow);
}


void gameRenderRect(SDL_Window *pWindow,SDL_Surface *pWindowSurf,ObjRect allObjRect[OBJRECT_MAX]) {
    int i;
    SDL_Rect srcRect;
    for (i=0;i<OBJRECT_MAX;i++) {
        srcRect.x = allObjRect[i].x;
        srcRect.y = allObjRect[i].y;
        srcRect.h = allObjRect[i].h;
        srcRect.w = allObjRect[i].w;
        SDL_FillRect(pWindowSurf,&srcRect,SDL_MapRGB(pWindowSurf->format,255,255,255));
    }
}


void gameRenderAnim(SDL_Window *pWindow,SDL_Surface *pWindowSurf,ObjAnim allObjAnim[OBJANIM_MAX]) {
    int i;
    SDL_Rect srcRect;
    for (i=0;i<OBJANIM_MAX;i++) {
        srcRect.x = allObjAnim[i].x;
        srcRect.y = allObjAnim[i].y;
        srcRect.h = allObjAnim[i].h;
        srcRect.w = allObjAnim[i].w;
        SDL_FillRect(pWindowSurf,&srcRect,SDL_MapRGB(pWindowSurf->format,50,50,50));
    }
}
