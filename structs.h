#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "defines.h"

struct Window {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};

struct Keyboard {
    int ArrowUp;
    int ArrowDown;
    int ArrowLeft;
    int ArrowRight;
    int Space;
    int Keyz;
    int Keyq;
    int Keys;
    int Keyd;

    //Keyboard mapping, feel free to add any key but make sure to add it in event.c as well (so it can be used)
};

struct Mouse {
    int MouseX;
    int MouseY;
    int MouseLeftClic;
    int MouseRightClic;
    int MouseWheelUp;
    int MouseWheelDown;
};

struct ObjBackground {
    SDL_Texture *pBGTexture; //pointer towards background texture
};

struct ObjRect {
    float x; //x pos
    float y; //y pos
    float w; //width
    float h; //height
    float speed; //speed (in pixels per second)
    Uint8 color_r; //Red colour
    Uint8 color_g; //Green colour
    Uint8 color_b; //Blue colour
    Uint8 color_a; //Opacity (0 = transparent / 255 = fully opaque)
};

struct ObjAnim {
    //In game stuff
    SDL_Rect inGamePos; //In game position - also collision box for now
    float speed; //speed (in pixels per second)
    SDL_Texture *pTexture; //pointer towards sprite texture
    SDL_Rect currentSpritePos; //current sprite rectangle. will change depending on animType and sprite dimensions.

    //Animation handling stuff
    int animType; //What is the object doing (example : idling, jumping, running, etc...) - Used to update the sprite position through the sprite sheet
    int spriteWidth; //Width of the sprite - So we can go to the next sprite according to animType
    int spriteHeight; //Height of the sprite - So we can go to the next sprite according to animType
    int spriteCurrent; //Which sprite are we currently rendering
    int spriteMax; //How many sprites are there here
    int framesPerSprite; //How long do we render each sprite
    int framesTimer; //How long do we render each sprite
    Uint8 color_r; //Sprite background colour to be erased : Red amount
    Uint8 color_g; //Sprite background colour to be erased : Green amount
    Uint8 color_b; //Sprite background colour to be erased : Blue amount

    //Note : This animation handling requires sprites to have the same size, and sheet to be carefully done.
    //We can save the colour variables by having the same colour to be erased for every sprite in our game (and then hardcoding the unwanted colour)
};

struct MasterObject {
    ObjBackground allObjBackground[OBJBACKGROUND_MAX];
    ObjRect allObjRect[OBJRECT_MAX];
    ObjAnim allObjAnim[OBJANIM_MAX];
};


//NOTE : below are ideas for an animated object. Unused for now.
/*struct anObject {
    //Elements de gestion macro
    int isDead; //0 ou 1 - Raccourci pour savoir si on le traite ou pas du tout
    int isMovable; //0 ou 1 - Il peut bouger ?
    int isRenderable; //0 ou 1 - Il faut le render ou pas ?
    int isCollisionable; //0 ou 1 - Il collisionne ou pas ?
    unsigned int type; //type de l'objet. A gérer avec des #define (ex : OBJECT_CIRCLE, OBJECT_ENNEMY, OBJECT_RECT, etc...) ; permet une gestion fine

    //Elements de gestion micro
    int x; //position en x
    int y; //position en y
    int w; //taille en largeur (si cercle : rayon)
    int h; //taille en hauteur
    int speed; //vitesse (en pixels par secondes)
    SDL_Surface *pSpriteSheet; //Adresse de la surface chargée avec la fiche de sprites
    int nbAnimations; //Nombre d'animations différentes
    int maxFramesPerAnim; //Nombre max de frames par animation

    int tableAnimations;

    //const int tableAnimations[nbAnimations][maxFramesPerAnim]; //matrice des animations

    //Idées à rajouter :
    // - Collision box/circle/autre?
};*/



#endif // STRUCTS_H_INCLUDED
