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
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

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

//rendered texture
LTexture gBlockTexture;

LBlock gBlock;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

bool init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	
	gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (gRenderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //THIS IS HOW YOU PUT COLOR ON THE RENDERER, putting an image on top just discards the color

	int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
		return false;
	}

	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);

	return true;
}


bool loadMedia()
{
	//Load sprites
	if (!gBlockTexture.loadFromFile("images/tetrisBlock.png", gRenderer)) {
		printf("Couldn't load tetrisBlock image!\n");
		return false;
	}

	return true;
}


void close()
{
	gBlockTexture.free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
		return 0;
	}

	//Load media
	if (!loadMedia())
	{
		printf("Failed to load media!\n");
		return 0;
	}

	//Event handler
	SDL_Event e;

	//Angle of rotation
	double degrees = 0;

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//While application is running
	while (true){

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){

			//User requests quit
			if (e.type == SDL_QUIT){

				close();
				return 0;
			}
			if (e.type == SDL_KEYDOWN) {

				switch (e.key.keysym.sym) {
					case SDLK_a:
						if (gBlock.mPosition.x - 1 >= 0) { gBlock.mPosition.x -= 1; }
						break;
					case SDLK_d:
						if (gBlock.mPosition.x + 1 <= 420) { gBlock.mPosition.x += 1; }
						break;
				}
			}
		}

		//clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		gBlock.render(&gBlockTexture, gRenderer);

		if (gBlock.mPosition.y < 580) {
			gBlock.mPosition.y += 1;
		}

		SDL_RenderPresent(gRenderer);
	}
}