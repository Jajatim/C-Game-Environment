#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED


//DEFINES
#define WINDOW_X 640 //Screen width (in pixels)
#define WINDOW_Y 480 //Screen height (in pixels)
#define NB_MAX_SURF 10 //Used to stored the maximum number of surfaces used in the software, so we can free them all at once when exiting.
//#define NB_MAX_OBJ 5 //Maximum game objects - DEPRECATED ! Now the maximum game objects is defined in the enumerations below, one enumeration for each object type.
#define UPDATE_TIMER 4 //Updates data every XX ms (Careful ! Keep this quite low or your render function will render useless garbage !)
#define RENDER_TIMER 16 //Render every object every XX ms (16ms = 60FPS)
#define CHUNK_SIZE_W 1000 //Chunk width (in pixels)
#define CHUNK_SIZE_H 1000 //Chunk height (in pixels)

//ENUMERATIONS - Makes it easier to know what object you're working on, and keeps track of the table size needed to store them.
enum eObjBackground {
    OBJBACKGROUND_MAIN, //Rename for something more appropriate...

    /* ADD NEW BACKGROUND OBJECTS HERE */

    OBJBACKGROUND_MAX //Enumeration ending, used as the table size to store them all
};

enum eObjRect {
    OBJRECT_PAD_LEFT,
    OBJRECT_PAD_RIGHT,
    OBJRECT_BALL,

    /* ADD NEW RECTANGLE OBJECTS HERE */

    OBJRECT_MAX //Enumeration ending, used as the table size to store them all
};

enum eObjAnim {
    OBJANIM_MAINCHAR, //Rename for something more appropriate...

    /* ADD NEW ANIMATED OBJECTS HERE */

    OBJANIM_MAX //Enumeration ending, used as the table size to store them all
};

/* If you need a new object type, create its enumeration here */


//TYPEDEFS
typedef struct Window Window;
typedef struct Keyboard Keyboard;
typedef struct Mouse Mouse;
typedef struct MainChar MainChar;
typedef struct ObjBackground ObjBackground;
typedef struct ObjRect ObjRect;
typedef struct ObjAnim ObjAnim;
typedef struct MasterObject MasterObject;
typedef struct MapChunk MapChunk;
typedef struct MapCurrent MapCurrent;
typedef struct MapGlobal MapGlobal;


#endif // DEFINES_H_INCLUDED
