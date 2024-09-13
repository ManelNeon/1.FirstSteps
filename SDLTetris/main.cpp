//SDL Libraries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Standard Libraries
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>

//Header Objects
#include "textureClasses.h"
#include "constantVariables.h"

LTexture gBlockTexture;

LTexture gScoreTextTexture;

LTexture gScoreValueTexture;

SDL_Color textColor{ 0,0,0 };

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

	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	if (MIX_INIT_MP3 != Mix_Init(MIX_INIT_MP3)) {
		printf("SDL_Mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
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

	gFont = TTF_OpenFont("fonts/ARCADE.ttf", 20);
	if (gFont == NULL) {
		printf("Couldn't load font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	if (!gScoreTextTexture.loadFromRenderedText("Score", textColor)) {
		printf("Failed to render texture!\n");
		return false;
	}

	gMusic = Mix_LoadMUS("audio/tetrisTheme.mp3");
	if (gMusic == NULL) {
		printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gBlockFallen = Mix_LoadWAV("audio/ballFall.wav");
	if (gBlockFallen == NULL) {
		printf("Failed to load audio! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gLineCleared = Mix_LoadWAV("audio/lineCleared.wav");
	if (gLineCleared == NULL) {
		printf("Failed to load audio! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	return true;
}

//Frees media and shuts down SDL
void close()
{
	gBlockTexture.free();

	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}

int quitGame() {

	for (size_t i{ 0 }; i < 80; ++i) {
		delete digitalBoard[i];
		digitalBoard[i] = NULL;
	}

	delete pBlock;
	pBlock = NULL;
	close();
	return 0;
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

	Mix_VolumeMusic(1);

	//While application is running
	while (true){

		if (Mix_PlayingMusic() == 0) {
			Mix_PlayMusic(gMusic, -1);
		}

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
				return quitGame();
			}

			//we move the block the player is controlling
			pBlock->handleEvent(e);
		}		

		//every 2 seconds we move the block down, and restart the timer
		if (blockFallTimer.getTicks() >= 500) {
			pBlock->move();
			blockFallTimer.stop();
			blockFallTimer.start();
		}

		//putting the text onto the string
		if (!gScoreValueTexture.loadFromRenderedText(std::to_string(gScore), textColor)) {
			printf("Unable to render score texture!\n");
			return 0;
		}

		//RENDERING THE SCREEN
		
		//clear screen
		SDL_SetRenderDrawColor(gRenderer, 255, 192, 203, 255);
		SDL_RenderClear(gRenderer);

		//checking if there's any blocks to render
		for (size_t i { 0 }; i < 80; ++i) {
			if (digitalBoard[i]) {
				digitalBoard[i]->render(&gBlockTexture);
			}
		}

		//rendering the block the player is controlling
		pBlock->render(&gBlockTexture);

		//Drawing a line
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderDrawLine(gRenderer, 480, 0, 480, SCREEN_HEIGHT);
		SDL_RenderDrawLine(gRenderer, 490, 0, 490, SCREEN_HEIGHT);

		//Rendering Text
		gScoreTextTexture.render(560, 100);

		gScoreValueTexture.render(575, 135);

		//updating the render
		SDL_RenderPresent(gRenderer);

		//CHECKS

		//in here we check if the block is still falling
		if (!pBlock->getIsFalling()) {

			bool lineDone = true;

			int currentRow = pBlock->getRow();

			if (pBlock->getRow() == 0) {
				return quitGame();
			}

			//if the block is not falling, then we save it in the digital board and we put the pBlock to null
			digitalBoard[pBlock->getRow() * 8 + pBlock->getColumn()] = pBlock;
			pBlock = NULL;

			//first we check if the whole line is covered
			for (size_t i{ 0 }; i < 8; ++i) {
				if (!digitalBoard[currentRow * 8 + i]) {
					lineDone = false;
					break;
				}
			}

			//in here we're checking if, in the case the whole line was covered, we will delete the previous blocks and move the others one row down
			if (lineDone) {
				gScore += 200;
				Mix_PlayChannel(-1, gLineCleared, 0);
				for (int i{ 0 }; i < 8; ++i) {
					for (int y{ 9 }; y >= 0; --y) {
						if (y == currentRow) {
							delete digitalBoard[currentRow * 8 + i];
							digitalBoard[currentRow * 8 + i] = NULL;
						}
						else if (digitalBoard[y * 8 + i]) {
							LBlock* currentBlock = digitalBoard[y * 8 + i];
							digitalBoard[y * 8 + i] = NULL;
							currentBlock->moveDown();
							digitalBoard[currentBlock->getRow() * 8 + currentBlock->getColumn()] = currentBlock;
						}
					}
					
				}
			}
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