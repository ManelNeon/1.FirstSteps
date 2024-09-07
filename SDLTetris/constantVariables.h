#ifndef CONSTANTVARIABLES_H
#define CONSTANTVARIABLES_H

#include <SDL.h>
#include "textureClasses.h"

//Screen Dimension Constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

//FPS Limiter
extern const int SCREEN_FPS;
extern const int SCREEN_TICKS_PER_FRAME;

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window we'll be rendering to
extern SDL_Renderer* gRenderer;

//The surface contained by the window
extern SDL_Surface* gScreenSurface;

//rows and columns
extern LBlock* digitalBoard[80];

#endif // !CONSTANTVARIABLES_H
