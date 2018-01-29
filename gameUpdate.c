#include "includes.h"

void gameUpdate(Uint32 deltatime,Keyboard *pKEYBOARD,anObject allObject[NB_MAX_OBJ]) {
    if (pKEYBOARD->ArrowLeft==1) {
        allObject[0].x -= 1;
    }
    if (pKEYBOARD->ArrowRight==1) {
        allObject[0].x += 1;
    }
    if (pKEYBOARD->ArrowUp==1) {
        allObject[0].y -= 1;
    }
    if (pKEYBOARD->ArrowDown==1) {
        allObject[0].y += 1;
    }
}

