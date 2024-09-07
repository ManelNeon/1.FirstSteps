//SDL Libraries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Standard Libraries
#include <vector>
#include <stdio.h>
#include <string>

//Header Objects
#include "textureClasses.h"
#include "constantVariables.h"

//rendered texture
LTexture gBlockTexture;

//Starts up SDL and creates window
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

//Loads media
bool loadMedia()
{
	//Load sprites
	if (!gBlockTexture.loadFromFile("images/tetrisBlock.png")) {
		printf("Couldn't load tetrisBlock image!\n");
		return false;
	}

	return true;
}

//Frees media and shuts down SDL
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

	LTimer capTimer;

	LTimer blockFallTimer;

	blockFallTimer.start();

	LBlock* pBlock = NULL;

	//While application is running
	while (true){

		//starting the capTimer, which limits our framerate to 60
		capTimer.start();

		//in here we check if pBlock is NULL, in case it is, we allocate new memory and basically create a new block
		if (pBlock == NULL) {
			pBlock = new LBlock;
		}

		//Handle events on queue, basically handle input from the player, in here is where we close the game and also delete every allocated memory
		while (SDL_PollEvent(&e) != 0){

			//User requests quit
			if (e.type == SDL_QUIT){

				for (size_t i{ 0 }; i < 80; ++i) {
					delete digitalBoard[i];
					digitalBoard[i] = NULL;
				}

				delete pBlock;
				pBlock = NULL;
				close();
				return 0;
			}

			//we move the block the player is controlling
			pBlock->handleEvent(e);
		}

		//every 2 seconds we move the block down, and restart the timer
		if (blockFallTimer.getTicks() == 200) {
			pBlock->move();
			blockFallTimer.stop();
			blockFallTimer.start();
		}

		//RENDERING THE SCREEN
		
		//clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//checking if there's any blocks to render
		for (size_t i { 0 }; i < 80; ++i) {
			if (digitalBoard[i]) {
				digitalBoard[i]->render(&gBlockTexture);
			}
		}

		//rendering the block the player is controlling
		pBlock->render(&gBlockTexture);

		//updating the render
		SDL_RenderPresent(gRenderer);


		//CHECKS

		//in here we check if the block is still falling, if not, we save it in the digital board and then we put the pblock to null
		if (!pBlock->getIsFalling()) {
			digitalBoard[pBlock->getRow() * pBlock->getColumn()] = pBlock;
			pBlock = NULL;
		}

		//frame limiter
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}