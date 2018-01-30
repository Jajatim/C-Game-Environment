#include "includes.h"

void gameRender(SDL_Window *pWindow,SDL_Surface *pWindowSurf,anObject allObject[NB_MAX_OBJ]) {
    /*SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(pWindow,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(pWindow);*/

    SDL_FillRect(pWindowSurf,NULL,SDL_MapRGB(pWindowSurf->format,0,0,0));
    //SDL_UpdateWindowSurface(pWindow);

    int i;
    SDL_Rect srcRect;
    for (i=0;i<NB_MAX_OBJ;i++) {
        srcRect.x = allObject[i].x;
        srcRect.y = allObject[i].y;
        srcRect.h = allObject[i].h;
        srcRect.w = allObject[i].w;
        SDL_FillRect(pWindowSurf,&srcRect,SDL_MapRGB(pWindowSurf->format,255,255,255));
    }

    SDL_UpdateWindowSurface(pWindow);
}
