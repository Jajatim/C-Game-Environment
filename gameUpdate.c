#include "includes.h"

void gameUpdate(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,MasterObject *pMasterObject) {
    //void gameUpdateBackground(); //Normally, doesn't need updating. Uncomment if needed
    gameUpdateMainChar(deltatime,pKeyboard,pMouse,pMasterObject->pMainChar,pMasterObject);
    gameUpdateRect(deltatime,pKeyboard,pMouse,pMasterObject->allObjRect);
    gameUpdateAnim(deltatime,pKeyboard,pMouse,pMasterObject->allObjAnim);
}


void gameUpdateMainChar(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,MainChar *pMainChar,MasterObject *pMasterObject) {

    float movement = pMainChar->speed*deltatime/1000.0;

    //0 : Yoshi -> animType : 1=idle_right 2=idle_left 3=move_right 4=move_left (need enumeration...)
    //Updating the movement
    if (pKeyboard->Keyq==1) {
        if (pMainChar->animType!=4) { //If it wasn't already moving left
            pMainChar->animType=4; //We update the animType
            pMainChar->spriteCurrent = 1; //We reset the sprite sequence to the beginning
            pMainChar->framesTimer = pMainChar->framesPerSprite; //We reset the timer
        }
        //pMainChar->inGamePosX -= pMainChar->speed*deltatime/1000.0;
        pMainChar->inGamePosX -= movement;
        pMasterObject->camX -= movement;
    }
    if (pKeyboard->Keyd==1) {
        if (pMainChar->animType!=3) { //If it wasn't already moving left
            pMainChar->animType=3; //We update the animType
            pMainChar->spriteCurrent = 1; //We reset the sprite sequence to the beginning
            pMainChar->framesTimer = pMainChar->framesPerSprite; //We reset the timer
        }
        //pMainChar->inGamePosX += pMainChar->speed*deltatime/1000.0;
        pMainChar->inGamePosX += movement;
        pMasterObject->camX += movement;
    }
    if (pKeyboard->Keyz==1) {
        //To animate !
        //pMainChar->inGamePosY -= pMainChar->speed*deltatime/1000.0;
        pMainChar->inGamePosY -= movement;
        pMasterObject->camY -= movement;
    }
    if (pKeyboard->Keys==1) {
        //To animate !
        //pMainChar->inGamePosY += pMainChar->speed*deltatime/1000.0;
        pMainChar->inGamePosY += movement;
        pMasterObject->camY += movement;
    }

    //Updating the animation
    //First we check if we just stopped (so we can go into idle mode)
    switch (pMainChar->animType) {
        case 3: //Moving right
            if (pKeyboard->Keyd==0) { //we WERE moving right, but we stopped
                pMainChar->animType=1; //We update the animType - now we're idling in the same direction
                pMainChar->spriteCurrent = 1; //We reset the sprite sequence to the beginning
                pMainChar->framesTimer = pMainChar->framesPerSprite; //We reset the timer
            }
            break;
        case 4: //Moving left
            if (pKeyboard->Keyq==0) { //we WERE moving left, but we stopped
                pMainChar->animType=2; //We update the animType - now we're idling in the same direction
                pMainChar->spriteCurrent = 1; //We reset the sprite sequence to the beginning
                pMainChar->framesTimer = pMainChar->framesPerSprite; //We reset the timer
            }
            break;
    }

    //decreasing the timer to next sprite
    pMainChar->framesTimer --;

    //If the timer is over
    if (pMainChar->framesTimer==0) {
        pMainChar->framesTimer = pMainChar->framesPerSprite; //We reset the timer
        pMainChar->spriteCurrent ++; //We go up in the animation sequence
        //If the sequence is over
        if (pMainChar->spriteCurrent>pMainChar->spriteMax) {
            pMainChar->spriteCurrent=1;//We reset it
        }
    }

    //We update the sprite position in the sprite sheet
    pMainChar->spritePos.x = pMainChar->spriteWidth*(pMainChar->spriteCurrent-1);
    pMainChar->spritePos.y = pMainChar->spriteHeight*(pMainChar->animType-1);
    //Width & Height do not change in this system
    //pMainChar->spritePos.w =
    //pMainChar->spritePos.h =
}


//void gameUpdateBackground() //Normally, doesn't need updating. Uncomment if needed


void gameUpdateRect(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,ObjRect allObjRect[OBJRECT_MAX]) {

    /* THIS IS COMMENTED PONG LIKE STUFF.

    //TEMP - INITIALIZE DATA WHEN BALL IS OUTSIDE THE SCREEN
    if (allObjRect[OBJRECT_BALL].x<0 || allObjRect[OBJRECT_BALL].x>WINDOW_X) {
        gameInitRect(allObjRect);
    }
    //END TEMP


    // -- See enum in defines.h for details --
    //0 : left pad
    //1 : right pad
    //2 : ball


    //0 : left pad (zqsd)
    if (pKeyboard->Keyz==1) {
        allObjRect[OBJRECT_PAD_LEFT].y -= allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }
    if (pKeyboard->Keyq==1) {
        allObjRect[OBJRECT_PAD_LEFT].x -= allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }
    if (pKeyboard->Keys==1) {
        allObjRect[OBJRECT_PAD_LEFT].y += allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }
    if (pKeyboard->Keyd==1) {
        allObjRect[OBJRECT_PAD_LEFT].x += allObjRect[OBJRECT_PAD_LEFT].speed*deltatime/1000;
    }


    //1 : right pad (arrow keys)
    if (pKeyboard->ArrowUp==1) {
        allObjRect[OBJRECT_PAD_RIGHT].y -= allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pKeyboard->ArrowLeft==1) {
        allObjRect[OBJRECT_PAD_RIGHT].x -= allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pKeyboard->ArrowDown==1) {
        allObjRect[OBJRECT_PAD_RIGHT].y += allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }
    if (pKeyboard->ArrowRight==1) {
        allObjRect[OBJRECT_PAD_RIGHT].x += allObjRect[OBJRECT_PAD_RIGHT].speed*deltatime/1000;
    }

    //2 : ball
    static float dirX=1; //X axis coefficient, here the ball goes straight on the X axis
    static float dirY=0; //Y axis coefficient, here the ball goes straight on the X axis
    //Note : Abolute values of x and y must add to make 1 in all cases (so the ball have a constant speed)

    //Collision ceiling
    if (allObjRect[OBJRECT_BALL].y<0) {
        dirY *= -1;
        allObjRect[OBJRECT_BALL].y=1;
    }

    //Collision floor
    if (allObjRect[OBJRECT_BALL].y+allObjRect[OBJRECT_BALL].h>WINDOW_Y) {
        dirY *= -1;
        allObjRect[OBJRECT_BALL].y=WINDOW_Y-allObjRect[OBJRECT_BALL].h-1;
    }

    //Check collision on the left pad (check starts 50px away from the pad)
    if (allObjRect[OBJRECT_BALL].x<allObjRect[OBJRECT_PAD_LEFT].x+50 && isColliding(allObjRect,2,0)==1) {

        //We check where the ball hits the pad (from 0 (top) to 1 (bottom)), we substract 0.5 so the ball will rebound accordingly
        dirY = ((allObjRect[OBJRECT_BALL].y + (allObjRect[OBJRECT_BALL].h/2)) - allObjRect[OBJRECT_PAD_LEFT].y) / allObjRect[OBJRECT_PAD_LEFT].h;
        dirY -= 0.5;

        //We recalculate X axis coefficient, who depends on Y axis coefficient so we stay at the same speed
        if (dirY<0) dirX = 1+dirY;
        else dirX = 1-dirY;
    }

    //Check collision on the right pad (check starts 50px away from the pad)
    if (allObjRect[OBJRECT_BALL].x>allObjRect[OBJRECT_PAD_RIGHT].x-50 && isColliding(allObjRect,2,1)==1) {

        //We check where the ball hits the pad (from 0 (top) to 1 (bottom)), we substract 0.5 so the ball will rebound accordingly
        dirY = ((allObjRect[OBJRECT_BALL].y + (allObjRect[OBJRECT_BALL].h/2)) - allObjRect[OBJRECT_PAD_RIGHT].y) / allObjRect[OBJRECT_PAD_RIGHT].h;
        dirY -= 0.5;

        //We recalculate X axis coefficient, who depends on Y axis coefficient so we stay at the same speed
        if (dirY<0) dirX = 1+dirY;
        else dirX = 1-dirY;

        //As we're recalculating the X axis coefficient, here we make the ball go left
        dirX *= -1;
    }

    //We move the ball, accordingly to the calculated coefficients and the speed
    allObjRect[OBJRECT_BALL].x += allObjRect[OBJRECT_BALL].speed*deltatime/1000 * dirX;
    allObjRect[OBJRECT_BALL].y += allObjRect[OBJRECT_BALL].speed*deltatime/1000 * dirY;

    */
}


void gameUpdateAnim(Uint32 deltatime,Keyboard *pKeyboard,Mouse *pMouse,ObjAnim allObjAnim[OBJANIM_MAX]) {

    //0 : Yoshi -> animType : 1=idle_right 2=idle_left 3=move_right 4=move_left (need enumeration...)
    //Updating the movement
    if (pKeyboard->Keyq==1) {
        if (allObjAnim[OBJANIM_MAINCHAR].animType!=4) { //If it wasn't already moving left
            allObjAnim[OBJANIM_MAINCHAR].animType=4; //We update the animType
            allObjAnim[OBJANIM_MAINCHAR].spriteCurrent = 1; //We reset the sprite sequence to the beginning
            allObjAnim[OBJANIM_MAINCHAR].framesTimer = allObjAnim[OBJANIM_MAINCHAR].framesPerSprite; //We reset the timer
        }
        //allObjAnim[OBJANIM_MAINCHAR].inGamePos.x -= allObjAnim[OBJANIM_MAINCHAR].speed*deltatime/1000.0;
        allObjAnim[OBJANIM_MAINCHAR].inGamePos.x -= (int)(allObjAnim[OBJANIM_MAINCHAR].speed*deltatime/1000.0);
    }
    if (pKeyboard->Keyd==1) {
        if (allObjAnim[OBJANIM_MAINCHAR].animType!=3) { //If it wasn't already moving left
            allObjAnim[OBJANIM_MAINCHAR].animType=3; //We update the animType
            allObjAnim[OBJANIM_MAINCHAR].spriteCurrent = 1; //We reset the sprite sequence to the beginning
            allObjAnim[OBJANIM_MAINCHAR].framesTimer = allObjAnim[OBJANIM_MAINCHAR].framesPerSprite; //We reset the timer
        }
        //allObjAnim[OBJANIM_MAINCHAR].inGamePos.x += allObjAnim[OBJANIM_MAINCHAR].speed*deltatime/1000.0;
        allObjAnim[OBJANIM_MAINCHAR].inGamePos.x += (int)(allObjAnim[OBJANIM_MAINCHAR].speed*deltatime/1000.0);
    }

    //Updating the animation
    //First we check if we just stopped (so we can go into idle mode)
    switch (allObjAnim[OBJANIM_MAINCHAR].animType) {
        case 3: //Moving right
            if (pKeyboard->Keyd==0) { //we WERE moving right, but we stopped
                allObjAnim[OBJANIM_MAINCHAR].animType=1; //We update the animType - now we're idling in the same direction
                allObjAnim[OBJANIM_MAINCHAR].spriteCurrent = 1; //We reset the sprite sequence to the beginning
                allObjAnim[OBJANIM_MAINCHAR].framesTimer = allObjAnim[OBJANIM_MAINCHAR].framesPerSprite; //We reset the timer
            }
            break;
        case 4: //Moving left
            if (pKeyboard->Keyq==0) { //we WERE moving left, but we stopped
                allObjAnim[OBJANIM_MAINCHAR].animType=2; //We update the animType - now we're idling in the same direction
                allObjAnim[OBJANIM_MAINCHAR].spriteCurrent = 1; //We reset the sprite sequence to the beginning
                allObjAnim[OBJANIM_MAINCHAR].framesTimer = allObjAnim[OBJANIM_MAINCHAR].framesPerSprite; //We reset the timer
            }
            break;
    }

    //decreasing the timer to next sprite
    allObjAnim[OBJANIM_MAINCHAR].framesTimer --;

    //If the timer is over
    if (allObjAnim[OBJANIM_MAINCHAR].framesTimer==0) {
        allObjAnim[OBJANIM_MAINCHAR].framesTimer = allObjAnim[OBJANIM_MAINCHAR].framesPerSprite; //We reset the timer
        allObjAnim[OBJANIM_MAINCHAR].spriteCurrent ++; //We go up in the animation sequence
        //If the sequence is over
        if (allObjAnim[OBJANIM_MAINCHAR].spriteCurrent>allObjAnim[OBJANIM_MAINCHAR].spriteMax) {
            allObjAnim[OBJANIM_MAINCHAR].spriteCurrent=1;//We reset it
        }
    }

    //We update the sprite position
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.x = allObjAnim[OBJANIM_MAINCHAR].spriteWidth*(allObjAnim[OBJANIM_MAINCHAR].spriteCurrent-1);
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.y = allObjAnim[OBJANIM_MAINCHAR].spriteHeight*(allObjAnim[OBJANIM_MAINCHAR].animType-1);
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.w = allObjAnim[OBJANIM_MAINCHAR].spriteWidth;
    allObjAnim[OBJANIM_MAINCHAR].currentSpritePos.h = allObjAnim[OBJANIM_MAINCHAR].spriteHeight;
}


int isColliding(ObjRect allObjRect[OBJRECT_MAX], int a, int b) {
    //Pas de collision en haut ?
    if (allObjRect[a].x>allObjRect[b].x+allObjRect[b].w) return 0;

    //Pas de collision en bas ?
    if (allObjRect[a].x+allObjRect[a].w<allObjRect[b].x) return 0;

    //Pas de collision à gauche ?
    if (allObjRect[a].y>allObjRect[b].y+allObjRect[b].h) return 0;

    //Pas de collision à droite ?
    if (allObjRect[a].y+allObjRect[a].h<allObjRect[b].y) return 0;

    return 1;
}
