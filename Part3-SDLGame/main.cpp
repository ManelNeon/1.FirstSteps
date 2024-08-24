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

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

/*
LTexture gPressTexture;

LTexture gUpTexture;

LTexture gDownTexture;

LTexture gLeftTexture;

LTexture gRightTexture;
*/

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
	/*
	if (!gPressTexture.loadFromFile("images/press.bmp", gRenderer)) {
		printf("Couldn't load press image!\n");
		return false;
	}

	if (!gUpTexture.loadFromFile("images/up.bmp", gRenderer)) {
		printf("Couldn't load up image!\n");
		return false;
	}

	if (!gDownTexture.loadFromFile("images/down.bmp", gRenderer)) {
		printf("Couldn't load down image!\n");
		return false;
	}

	if (!gLeftTexture.loadFromFile("images/left.bmp", gRenderer)) {
		printf("Couldn't load left image!\n");
		return false;
	}

	if (!gRightTexture.loadFromFile("images/right.bmp", gRenderer)) {
		printf("Couldn't load right image!\n");
		return false;
	}
	*/

	return true;
}


void close()
{
	//Free Textures
	/*
	gPressTexture.free();
	gUpTexture.free();
	gDownTexture.free();
	gLeftTexture.free();
	gRightTexture.free();
	*/


	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Getting off Subsystems
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

	LTexture* currentTexture = NULL;

	//While application is running
	while (true){

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){

			//User requests quit
			if (e.type == SDL_QUIT){

				close();
				return 0;
			}
		}
		/*
		//With this code we're able to get the keyboard state, what this does different from the previous way is that it checks if the player is still holding and only does the action
		//when the player is holding the key. In this case if we're not pressing anything, we're getting the press texture. I think this is better for movement!
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		
		if (currentKeyStates[SDL_SCANCODE_UP]) {
			currentTexture = &gUpTexture;
		}
		else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
			currentTexture = &gDownTexture;
		}
		else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
			currentTexture = &gLeftTexture;
		}
		else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
			currentTexture = &gRightTexture;
		}
		else{
			currentTexture = &gPressTexture;
		}*/
		
		//clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//currentTexture->render(0, 0, gRenderer);

		SDL_RenderPresent(gRenderer);
	}
}