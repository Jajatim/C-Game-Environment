#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "defines.h"

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

    //A compléter. Les modifications doivent être rajoutées dans le fichier event.c pour être prises en compte.
};

struct anObject {
    float x; //position en x
    float y; //position en y
    float w; //taille en largeur (si cercle : rayon)
    float h; //taille en hauteur
    float speed; //vitesse (en pixels par secondes)
};

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
