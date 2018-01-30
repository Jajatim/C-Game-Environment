#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED


//Defines
#define WINDOW_X 640 //Taille de l'�cran en largeur
#define WINDOW_Y 480 //Taille de l'�cran en longueur
#define NB_MAX_SURF 10 //Nombre de surfaces maximum dans tout le programme (utilis� pour faire des free automatiquement)
//#define NB_MAX_OBJ 5 //Nombre maximum d'objets de jeu - d�pr�ci�, remplac� par la valeur finale de l'enumeration ci dessous.
#define UPDATE_TIMER 4 //Met les donn�es � jour tous les XX ms (attention � mettre un timer d'update strictement inf�rieur au timer du render !)
#define RENDER_TIMER 16 //Affiche les objets tous les XX ms (16ms = 60FPS environ)

//Enums - Makes it easier to know what object you're working on.
enum eObjRect {
    OBJRECT_PAD_LEFT,
    OBJRECT_PAD_RIGHT,
    OBJRECT_BALL,

    /* ADD NEW RECTANGLE OBJECTS HERE */

    OBJRECT_MAX
};

enum eObjAnim {
    OBJANIM_BACKGROUND,

    /* ADD NEW ANIMATED OBJECTS HERE */

    OBJANIM_MAX
};

//TypeDef
typedef struct Keyboard Keyboard;
typedef struct ObjRect ObjRect;
typedef struct ObjAnim ObjAnim;
typedef struct MasterObject MasterObject;


#endif // DEFINES_H_INCLUDED
