#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED


//Defines
#define WINDOW_X 640 //Taille de l'écran en largeur
#define WINDOW_Y 480 //Taille de l'écran en longueur
#define NB_MAX_SURF 10 //Nombre de surfaces maximum dans tout le programme (utilisé pour faire des free automatiquement)
#define NB_MAX_OBJ 5 //Nombre maximum d'objets de jeu
#define UPDATE_TIMER 4 //Met les données à jour tous les XX ms (conseillé au moins 4 fois par affichage)
#define RENDER_TIMER 16 //Affiche les objets tous les XX ms


//TypeDef
typedef struct Keyboard Keyboard;
typedef struct anObject anObject;


#endif // DEFINES_H_INCLUDED
