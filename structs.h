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
    SDL_Texture *pBGTexture; //pointer towards background structure
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
    float x; //x pos
    float y; //y pos
    float w; //width
    float h; //height
    float speed; //speed (in pixels per second)

    //NOTE : same as ObjRect for testing purposes
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
