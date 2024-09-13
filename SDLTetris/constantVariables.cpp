#include "constantVariables.h"

//Screen dimension constants
const int SCREEN_WIDTH = 720; //480
const int SCREEN_HEIGHT = 600;

//FPS Limiter
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window we'll be rendering to
SDL_Renderer* gRenderer = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

Mix_Music* gMusic = NULL;

Mix_Chunk* gBlockFallen = NULL;

Mix_Chunk* gLineCleared = NULL;

int gScore = NULL;

LBlock* pBlock = NULL;

TTF_Font* gFont = NULL;

//rows and columns (row * 8 + column)
LBlock* digitalBoard[80] = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};