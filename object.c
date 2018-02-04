#include "includes.h"

void createMaster(MasterObject *pMasterObject) {
    //Camera initialization
    pMasterObject->camX = 0;
    pMasterObject->camY = 0;

    createMainChar(pMasterObject->pMainChar);
    createObjBackground(pMasterObject->allObjBackground);
    createObjRect(pMasterObject->allObjRect);
    createObjAnim(pMasterObject->allObjAnim);
}


void createMainChar(MainChar *pMainChar) {
    pMainChar->inGamePosX=0.0;
    pMainChar->inGamePosY=0.0;
    pMainChar->speed=0.0;
    pMainChar->pTexture=NULL;

    pMainChar->spritePos.x=0;
    pMainChar->spritePos.y=0;
    pMainChar->spritePos.w=0;
    pMainChar->spritePos.h=0;

    pMainChar->animType = 1; //Need enumeration, or we'll get lost later on... Here : 1=idle_right 2=idle_left 3=move_right 4=move_left
    pMainChar->spriteWidth = 0;
    pMainChar->spriteHeight = 0;
    pMainChar->spriteCurrent = 1;

    pMainChar->spriteMax = 0;
    pMainChar->framesPerSprite = 0;
    pMainChar->framesTimer = 0;

    pMainChar->color_r = -1;
    pMainChar->color_g = -1;
    pMainChar->color_b = -1;
}


void createObjBackground(ObjBackground allObjBackground[OBJBACKGROUND_MAX]) {
    int i;
    for (i=0;i<OBJBACKGROUND_MAX;i++) {
        allObjBackground[i].pBGTexture=NULL;
    }
}

void createObjRect(ObjRect allObjRect[OBJRECT_MAX]) {
    int i;
    for (i=0;i<OBJRECT_MAX;i++) {
        allObjRect[i].x=0.0;
        allObjRect[i].y=0.0;
        allObjRect[i].w=0.0;
        allObjRect[i].h=0.0;
        allObjRect[i].speed=0.0;
        allObjRect[i].color_r=255; //White by default
        allObjRect[i].color_g=255; //White by default
        allObjRect[i].color_b=255; //White by default
        allObjRect[i].color_a=255; //Opaque by default
    }
}

void createObjAnim(ObjAnim allObjAnim[OBJANIM_MAX]) {
    int i;
    for (i=0;i<OBJANIM_MAX;i++) {
        allObjAnim[i].inGamePos.x=0;
        allObjAnim[i].inGamePos.y=0;
        allObjAnim[i].inGamePos.w=0;
        allObjAnim[i].inGamePos.h=0;
        allObjAnim[i].currentSpritePos.x=0;
        allObjAnim[i].currentSpritePos.y=0;
        allObjAnim[i].currentSpritePos.w=0;
        allObjAnim[i].currentSpritePos.h=0;
        allObjAnim[i].speed=0.0;
        allObjAnim[i].pTexture=NULL;

        allObjAnim[i].animType = 1; //Need enumeration, or we'll get lost later on... Here : 1=idle_right 2=idle_left 3=move_right 4=move_left
        allObjAnim[i].spriteWidth = 0;
        allObjAnim[i].spriteHeight = 0;
        allObjAnim[i].spriteCurrent = 1;

        allObjAnim[i].spriteMax = 0;
        allObjAnim[i].framesPerSprite = 0;
        allObjAnim[i].framesTimer = 0;

        allObjAnim[i].color_r = -1;
        allObjAnim[i].color_g = -1;
        allObjAnim[i].color_b = -1;
    }
}




/* MAP GENERATION */


void createMapGlobal(SDL_Renderer *pRenderer,MapCurrent *pMapCurrent,MapGlobal *pMapGlobal,MapChunk *pMapChunk) {
    //Putting a chunk in every case of the matrix
    int i,j;
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            createMapChunk(pRenderer,pMapChunk); //we update a chunk with its random value

            //We update its X position from X-chunkWidth to X+chunkWidth
            if (i==0) {
                pMapChunk->chunkPos.x = CHUNK_SIZE_W*-1;
            }
            else if(i==2) {
                pMapChunk->chunkPos.x = CHUNK_SIZE_W;
            }

            //We update its Y position from Y-chunkHeight to Y+chunkHeight
            if (j==0) {
                pMapChunk->chunkPos.y = CHUNK_SIZE_H*-1;
            }
            else if(j==2) {
                pMapChunk->chunkPos.y = CHUNK_SIZE_H;
            }

            //We store this chunk in the matrix
            pMapCurrent->tableCurrentChunks[i][j] = *pMapChunk;
        }
    }

    //Put the current chunks in the global chunks
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            pMapGlobal->tableAllChunks[i][j] = pMapCurrent->tableCurrentChunks[i][j];
        }
    }
}


void createMapChunk(SDL_Renderer *pRenderer,MapChunk *pMapChunk) {
    pMapChunk->chunkPos.x = 0;
    pMapChunk->chunkPos.y = 0;
    pMapChunk->chunkPos.w = CHUNK_SIZE_W;
    pMapChunk->chunkPos.h = CHUNK_SIZE_H;

    pMapChunk->chunkType = 0; //Need to set this to random
    pMapChunk->pChunkTexture = fNewTextureFromBMP(pRenderer,"aaa.bmp"); //Replace "aaa.bmp" with a bmp file of yours
}
