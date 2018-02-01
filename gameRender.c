#include "includes.h"


// NEED REWORK TO WORK WITH RENDERERS !

void gameRender(Window *pWindowStruct,MasterObject *pMasterObject) {

    //Screen erase (well, covers it in black...)
    SDL_SetRenderDrawColor(pWindowStruct->pRenderer,0,0,0,255);
    SDL_RenderClear(pWindowStruct->pRenderer);

    //Calls sub renders
    gameRenderBackground(pWindowStruct->pRenderer,pMasterObject->allObjBackground);
    gameRenderRect(pWindowStruct->pRenderer,pMasterObject->allObjRect);
    gameRenderAnim(pWindowStruct->pRenderer,pMasterObject->allObjAnim);

    /*
    PROBLEM : Can't choose rendering order...
        -> for example : If we render a very large Animated Object here, we wouldn't see the rectangles

    SOLUTION 1 : "Buffering" all objects in smaller MasterObjects according to a "turn order" (member of structs, user defined) maybe ?
        -> Sounds slow but might work.
    SOLUTION 2 : Creating objects and members in the right order maybe ?.
        -> Sounds like lots of work for starters, and awful maintenance. We wouldn't be able to have exceptions as well...
    */

    SDL_RenderPresent(pWindowStruct->pRenderer);
}


void gameRenderBackground(SDL_Renderer *pRenderer,ObjBackground allObjBackground[OBJBACKGROUND_MAX]){
    int i;
    for (i=0;i<OBJBACKGROUND_MAX;i++) {
        if (allObjBackground[i].pBGTexture != NULL) {
            SDL_RenderCopy(pRenderer,allObjBackground[i].pBGTexture,NULL,NULL);
        }
    }
}


void gameRenderRect(SDL_Renderer *pRenderer,ObjRect allObjRect[OBJRECT_MAX]) {
    int i;
    SDL_Rect srcRect;
    for (i=0;i<OBJRECT_MAX;i++) {
        srcRect.x = allObjRect[i].x;
        srcRect.y = allObjRect[i].y;
        srcRect.h = allObjRect[i].h;
        srcRect.w = allObjRect[i].w;

        SDL_SetRenderDrawColor(pRenderer,allObjRect[i].color_r,allObjRect[i].color_g,allObjRect[i].color_b,allObjRect[i].color_a);
        SDL_RenderFillRect(pRenderer,&srcRect);
    }
}


void gameRenderAnim(SDL_Renderer *pRenderer,ObjAnim allObjAnim[OBJANIM_MAX]) {

}
