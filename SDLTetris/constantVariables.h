#ifndef CONSTANTVARIABLES_H
#define CONSTANTVARIABLES_H

//SDL Libraries
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

//Standard Libraries
#include <vector>

//Header Files
#include "textureClasses.h"

class LBlock;

class LTexture;

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

extern Mix_Music* gMusic;

extern Mix_Chunk* gBlockFallen;

extern Mix_Chunk* gLineCleared;

extern int gScore;

extern std::vector<LBlock*> pBlock;

extern TTF_Font* gFont;

//rows and columns
extern LBlock* digitalBoard[80];

#endif // !CONSTANTVARIABLES_H
