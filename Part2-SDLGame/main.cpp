/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "textureClasses.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window we'll be rendering to
SDL_Renderer* gRenderer = NULL;

//Gloably used font
TTF_Font* gFont = NULL;

//rendered texture
LTexture gTextTexture;

LTexture gFooTexture;

const int WALKING_ANIMATION_FRAMES = 4;

SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //THIS IS HOW YOU PUT COLOR ON THE RENDERER, putting an image on top just discards the color

				int imgFlags = IMG_INIT_JPG;

				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
					success = false;
				}
				else {
					imgFlags = IMG_INIT_PNG;
					if (!(IMG_Init(imgFlags) & imgFlags)) {
						printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
						success = false;
					}
					else {

						if (TTF_Init() == -1) {
							printf("SDLttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
							success = false;
						}

						//Get window surface
						gScreenSurface = SDL_GetWindowSurface(gWindow);
					}
				}
			}
		}
	}

	return success;
}


bool loadMedia()
{
	//Loading success flag
	bool success = true;
	
	if (!gFooTexture.loadFromFile("images/fooWalking.png", gRenderer)) {
		printf("Could not load foo's spritesheet!\n");
		success = false;
	}
	else {

		//Set sprite clips
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 64;
		gSpriteClips[0].h = 205;

		gSpriteClips[1].x = 64;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 64;
		gSpriteClips[1].h = 205;

		gSpriteClips[2].x = 128;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 64;
		gSpriteClips[2].h = 205;

		gSpriteClips[3].x = 192;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 64;
		gSpriteClips[3].h = 205;
	}

	gFont = TTF_OpenFont("fonts/arcade.ttf", 28);
	if (gFont == NULL) {
		printf("Failed to load arcade font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else {
		SDL_Color textColor{ 0,0,0 };
		if (!gTextTexture.loadFromRenderedText("Welcome To Tetris!", textColor, gFont, gRenderer)) {
			printf("Failed to render texture!\n");
			success = false;
		}
	}

	return success;
}


void close()
{
	gTextTexture.free();
	gFooTexture.free();

	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//frames
			int frame = 0;

			//Angle of rotation
			double degrees = 0;

			//Flip type
			SDL_RendererFlip flipType = SDL_FLIP_NONE;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN) {
						switch (e.key.keysym.sym) {
							case SDLK_a:
								degrees -= 60;
								break;
							case SDLK_d:
								degrees += 60;
								break;
							case SDLK_q:
								flipType = SDL_FLIP_HORIZONTAL;
								break;
							case SDLK_w:
								flipType = SDL_FLIP_NONE;
								break;
							case SDLK_e:
								flipType = SDL_FLIP_VERTICAL;
								break;
						}
					}
				}

				//clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				
				//making the frames cycle
				SDL_Rect* currentClip = &gSpriteClips[frame / 8];
				gFooTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, gRenderer , currentClip, degrees, NULL, flipType);

				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT - 50, gRenderer);

				SDL_RenderPresent(gRenderer);

				++frame;
				
				if (frame / 8 >= WALKING_ANIMATION_FRAMES) {
					frame = 0;
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}