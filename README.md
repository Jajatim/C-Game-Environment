# C-Game-Environment
Basic environment for games, coded in C

*01/02/2018 - Big update \o/ (mainly : textures, mouse input and maintenance, see bottom of this readme for the list)*

*31/01/2018 - Now in english \o/*

*30/01/2018 - Added a pong to try my own medicine \o/*

*29/01/2018 - Now working with rectangles \o/*

What you need to use this ?
- SDL 2


What to do with that ?
- Initialize all objects in gameInit.c (it is safe to delete everything in the function)
- Update whatever you like in gameUpdate.c (it is safe to delete everything in the function)


More specific things to do ?
- Choose window size, max objects, render&update timers in define.h
- If you need to render something differently from a rectangle, you can have a peek in render.c


What's to come ?
- More in depth object configuration and possibilities
- Object animation (with sprite sheets)
- We'll see



01 February 2018 update content :
- Now uses the renderers instead of the surfaces.
- Added a structure for both the window and the renderer.
- Added a new object called background so you can add one.
- Added new function to load a texture from a BMP file.
- Fixed all render with new use of renderers
- Added mouse input (except wheel, double click, and maybe other stuff i didn't think of).
- Fixed the event manager : now in a while instead of a if
- Deleted some functions to handle surfaces (as it's not needed anymore, some are kept while finishing the update)
- Other stuff I can't remember...
