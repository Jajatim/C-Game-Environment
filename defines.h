#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED


//DEFINES
#define WINDOW_X 640 //Screen width (in pixels)
#define WINDOW_Y 480 //Screnn height (in pixels)
#define NB_MAX_SURF 10 //Used to stored the maximum number of surfaces used in the software, so we can free them all at once when exiting.
//#define NB_MAX_OBJ 5 //Maximum game objects - DEPRECATED ! Now the maximum game objects is defined in the enumerations below, one enumeration for each object type.
#define UPDATE_TIMER 4 //Updates data every XX ms (Careful ! Keep this quite low or your render function will render useless garbage !)
#define RENDER_TIMER 16 //Render every object every XX ms (16ms = 60FPS)

//ENUMERATIONS - Makes it easier to know what object you're working on, and keeps track of the table size needed to store them.
enum eObjRect {
    OBJRECT_PAD_LEFT,
    OBJRECT_PAD_RIGHT,
    OBJRECT_BALL,

    /* ADD NEW RECTANGLE OBJECTS HERE */

    OBJRECT_MAX //Enumeration ending, used as the table size to store them all
};

enum eObjAnim {
    OBJANIM_BACKGROUND,

    /* ADD NEW ANIMATED OBJECTS HERE */

    OBJANIM_MAX //Enumeration ending, used as the table size to store them all
};

/* If you need a new object type, create its enumeration here */


//TYPEDEFS
typedef struct Keyboard Keyboard;
typedef struct ObjRect ObjRect;
typedef struct ObjAnim ObjAnim;
typedef struct MasterObject MasterObject;


#endif // DEFINES_H_INCLUDED
