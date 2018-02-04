#include "includes.h"

void gameRender(Window *pWindowStruct,MasterObject *pMasterObject,MapCurrent *pMapCurrent) {

    //Screen erase (well, covers it in black...)
    SDL_SetRenderDrawColor(pWindowStruct->pRenderer,200,200,200,255);
    SDL_RenderClear(pWindowStruct->pRenderer);

    //Rendering the map
    gameRenderMap(pWindowStruct->pRenderer,pMapCurrent,pMasterObject);

    //Calls sub renders
    gameRenderBackground(pWindowStruct->pRenderer,pMasterObject->allObjBackground);
    gameRenderMainChar(pWindowStruct->pRenderer,pMasterObject->pMainChar,pMasterObject);
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


void gameRenderMap(SDL_Renderer *pRenderer,MapCurrent *pMapCurrent,MasterObject *pMasterObject) {
    int i,j;
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            SDL_Rect rectDST;
            rectDST.x = pMapCurrent->tableCurrentChunks[i][j].chunkPos.x - pMasterObject->camX;
            rectDST.y = pMapCurrent->tableCurrentChunks[i][j].chunkPos.y - pMasterObject->camY;
            rectDST.w = CHUNK_SIZE_W;
            rectDST.h = CHUNK_SIZE_H;

            SDL_RenderCopy(pRenderer,pMapCurrent->tableCurrentChunks[i][j].pChunkTexture,NULL,&rectDST);
        }
    }
}


void gameRenderBackground(SDL_Renderer *pRenderer,ObjBackground allObjBackground[OBJBACKGROUND_MAX]){
    /*int i;
    for (i=0;i<OBJBACKGROUND_MAX;i++) {
        if (allObjBackground[i].pBGTexture != NULL) {
            SDL_RenderCopy(pRenderer,allObjBackground[i].pBGTexture,NULL,NULL);
        }
    }*/
}


void gameRenderMainChar(SDL_Renderer *pRenderer,MainChar *pMainChar,MasterObject *pMasterObject){
    if (pMainChar->pTexture != NULL) {

        //Where to render our character on screen
        SDL_Rect rectDST;
        rectDST.x = pMainChar->inGamePosX - pMasterObject->camX;
        rectDST.y = pMainChar->inGamePosY - pMasterObject->camY;
        rectDST.w = pMainChar->spritePos.w*4; //4 times the sprite width, because why not
        rectDST.h = pMainChar->spritePos.h*4; //4 times the sprite height, because why not

        SDL_RenderCopy(pRenderer,pMainChar->pTexture,&pMainChar->spritePos,&rectDST);
    }
}


void gameRenderRect(SDL_Renderer *pRenderer,ObjRect allObjRect[OBJRECT_MAX]) {
    /*int i;
    SDL_Rect srcRect;
    for (i=0;i<OBJRECT_MAX;i++) {
        srcRect.x = allObjRect[i].x;
        srcRect.y = allObjRect[i].y;
        srcRect.h = allObjRect[i].h;
        srcRect.w = allObjRect[i].w;

        SDL_SetRenderDrawColor(pRenderer,allObjRect[i].color_r,allObjRect[i].color_g,allObjRect[i].color_b,allObjRect[i].color_a);
        SDL_RenderFillRect(pRenderer,&srcRect);
    }*/
}


void gameRenderAnim(SDL_Renderer *pRenderer,ObjAnim allObjAnim[OBJANIM_MAX]) {
    /*int i;
    for (i=0;i<OBJANIM_MAX;i++) {
        if (allObjAnim[i].pTexture != NULL) {
            SDL_RenderCopy(pRenderer,allObjAnim[i].pTexture,&allObjAnim[i].currentSpritePos,&allObjAnim[i].inGamePos);
        }
    }*/
}
