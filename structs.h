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

struct MainChar {
    //In game stuff
    float inGamePosX; //Float, so it stills moves when travelled distance is something like 0.02 pixels.
    float inGamePosY; //Float, so it stills moves when travelled distance is something like 0.02 pixels.
    //How to handle inGame width and height ? For now, it is defined in the render

    float speed; //speed (in pixels per second)
    SDL_Texture *pTexture; //pointer towards sprite texture
    SDL_Rect spritePos; //Sprite rectangle in the sprite sheet

    //Animation handling stuff
    int animType; //What is the object doing (example : idling, jumping, running, etc...) - Used to update the sprite position through the sprite sheet
    int spriteWidth; //Width of the sprite - So we can go to the next sprite according to animType
    int spriteHeight; //Height of the sprite - So we can go to the next sprite according to animType
    int spriteCurrent; //Which sprite are we currently rendering
    int spriteMax; //How many sprites are there here
    int framesPerSprite; //How long do we render each sprite - Careful, it depends on the updates or render timers set in defines.h
    int framesTimer; //How long do we render each sprite
    Uint8 color_r; //Sprite background colour to be erased : Red amount
    Uint8 color_g; //Sprite background colour to be erased : Green amount
    Uint8 color_b; //Sprite background colour to be erased : Blue amount

    //Note : This animation handling requires sprites to have the same size, and sheet to be carefully done.
    //We can save the colour variables by having the same colour to be erased for every sprite in our game (and then hardcoding the unwanted colour)
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
    int framesPerSprite; //How long do we render each sprite - Careful, it depends on the updates or render timers set in defines.h
    int framesTimer; //How long do we render each sprite
    Uint8 color_r; //Sprite background colour to be erased : Red amount
    Uint8 color_g; //Sprite background colour to be erased : Green amount
    Uint8 color_b; //Sprite background colour to be erased : Blue amount

    //Note : This animation handling requires sprites to have the same size, and sheet to be carefully done.
    //We can save the colour variables by having the same colour to be erased for every sprite in our game (and then hardcoding the unwanted colour)
};

struct MasterObject {
    float camX; //camera position on X
    float camY; //camera position on Y
    MainChar *pMainChar;
    ObjBackground allObjBackground[OBJBACKGROUND_MAX];
    ObjRect allObjRect[OBJRECT_MAX];
    ObjAnim allObjAnim[OBJANIM_MAX];
};








// LET'S CREATE AN INFINITE MAP !! (don't worry, this chirpy optimism will fade soon :D)

//Let's try this method :
// - We create chunks (empty for now).
// - These chunks will be found (and named) by their position. For example : Starting chunk is X0/Y0, right chunk is X+ChunkWidth/Y0
// - We keep in memory and update only the chunks around the camera (let's say a 3*3 grid, that's 9 chunks)
// - For now, we add all new chunks in a "mapGlobal" structure, which contains all the chunks created so far (malloc it up \o/)
// - Later on, we'll need to dump this structure into a file cause it's useless data

struct MapChunk {
    SDL_Rect chunkPos; //Contains the position of the chunk

    //Included for testing purposes : To be updated.
    int chunkType; //Type of the chunk, so we can load the right texture on it and check if what we're doing is working properly
    SDL_Texture *pChunkTexture; //pointer towards background texture

    //Later, we'll divide each chunk in a tile grid so we can save objects and other stuff.
};

//Current chunks in memory (the part of the map that we update/render)
//For now, we only load 9 chunks in this structure, this might need to be upgraded to 25 chunks ? Or divided in chunks to update and chunks to render? We'll see
struct MapCurrent {
    MapChunk tableCurrentChunks[3][3]; //If we are in chunk O/0, this table will contain chunks from X-ChunkWidth to X+ChunkWidth and Y-ChunkHeight to Y+ChunkWidth
};

//Contains the whole map. Temporary, we should update this system to load and unload the mapCurrent from a file, so this structure won't be too big.
struct MapGlobal {
    MapChunk tableAllChunks[3][3]; //Memory needs to be allocated dynamically to store newly created chunks. Starts at 9 though as we start our world with only 9 chunks.
};


#endif // STRUCTS_H_INCLUDED
