#include "includes.h"

Uint32 fTimer() {
    Uint32 currentTick = SDL_GetTicks();
    static Uint32 lastTick=0;
    Uint32 deltaTime = 0;

    //Au premier passage, on initialise le lastTick, on ne sait donc pas à combien est le delta, on renvoie 0
    if (lastTick==0) {
        lastTick = currentTick;
        return 0;
    }

    //Pour les autres passages, on renvoie le delta
    deltaTime = currentTick-lastTick;
    lastTick = currentTick;

    return deltaTime;
}
