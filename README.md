# C-Game-Environment
Basic environment for games, coded in C

*29/01/2018 - Now working with rectangles \o/*

What you need to use this ?
- SDL 2


What to do with that ?
- Initialize all objects in gameInit.c  (it is safe to delete everything in the function)
- Update whatever you like in gameUpdate.c (it is safe to delete everything in the function)


More specific things to do ?
- Choose window size, max objects in define.h (default : 640x480 and 100 objects max)
- If you need to render something differently from a regular square, you can have a peek in render.c


What's to come ?
- More in depth object configuration and possibilities
- Possibility to modify FPS to render (user defined)
- Limitation of updates up to X times per render (user defined)
- Object animation (with sprite sheets)
- We'll see
