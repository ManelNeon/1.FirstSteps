/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "textureClasses.h"
#include "globalVariables.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

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

LTexture gStartPrompt;

LTexture gBlockTexture;

LTexture gPausePrompt;

LTexture gTimeTexture;

TTF_Font* gFont;

/*
//Mix Music for music, Mix Chunk for sound effects

//the music that will be played
Mix_Music* gMusic = NULL;

//the sound effects that will be used
Mix_Chunk* gScratch = NULL;
Mix_Chunk* gHigh = NULL;
Mix_Chunk* gMedium = NULL;
Mix_Chunk* gLow = NULL;
*/

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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

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

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);

	return true;
}


bool loadMedia()
{
	if (!gBlockTexture.loadFromFile("images/tetrisBlock.png", gRenderer)) {
		printf("Couldn't load block texture!\n");
		return false;
	}

	/*
	gFont = TTF_OpenFont("fonts/arcade.ttf", 28);
	if (gFont == NULL) {
		printf("Failed to load arcade font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	SDL_Color textColor = { 0, 0, 0, 255 };
	*/

	/*
	if (!gStartPrompt.loadFromRenderedText("Press S to Start or Stop the Timer", textColor, gRenderer, gFont)) {
		printf("Unable to render prompt texture!\n");
		return false;
	}

	if (!gPausePrompt.loadFromRenderedText("Press P to Pause or Unpause the Timer", textColor, gRenderer, gFont)) {
		printf("Unable to render prompt texture!\n");
		return false;
	}*/

	/*
	if (!gBaseTexture.loadFromFile("images/soundPrompt.png", gRenderer)) {
		printf("Couldn't load prompt texture!\n");
		return false;
	}

	//Loading Music
	gMusic = Mix_LoadMUS("sound/beat.wav");
	if (gMusic == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gScratch = Mix_LoadWAV("sound/scratch.wav");
	if (gScratch == NULL) {
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gHigh = Mix_LoadWAV("sound/high.wav");
	if (gHigh == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gMedium = Mix_LoadWAV("sound/medium.wav");
	if (gMedium == NULL)
	{
		printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gLow = Mix_LoadWAV("sound/low.wav");
	if (gLow == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}*/

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
	gStartPrompt.free();
	gPausePrompt.free();
	gTimeTexture.free();

	//Free Sound Effects
	/*
	Mix_FreeChunk(gScratch);
	Mix_FreeChunk(gHigh);
	Mix_FreeChunk(gMedium);
	Mix_FreeChunk(gLow);
	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;
	

	//Free Music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
	*/

	//Free Font
	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Getting off Subsystems
	Mix_Quit();
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

	Dot dot;

	SDL_Color textColor = { 0, 0, 0, 255 };

	//Uint32 startTime = 0;

	LTimer capTimer;

	//LTimer fpsTimer;

	//std::stringstream timeText;


	//int countedFrames = 0;
	//fpsTimer.start();

	//LTexture* currentTexture = NULL;

	//While application is running
	while (true){

		capTimer.start();

		//Handle events on queue
		/*while (SDL_PollEvent(&e) != 0) {

			//User requests quit
			if (e.type == SDL_QUIT){

				close();
				return 0;
			}
			else if (e.type == SDL_KEYDOWN) {
				/*
				if (e.key.keysym.sym == SDLK_s) {
					if (timer.isStarted()) {
						timer.stop();
					}
					else {
						timer.start();
					}
				}
				else if (e.key.keysym.sym == SDLK_p) {
					if (timer.isPaused()) {
						timer.unpause();
					}
					else {
						timer.pause();
					}
				}
				//startTime = SDL_GetTicks();
				switch (e.key.keysym.sym) {
					
					case SDLK_1:
						Mix_PlayChannel(-1, gHigh, 0);
						break;
					case SDLK_2:
						Mix_PlayChannel(-1, gMedium, 0);
						break;
					case SDLK_3:
						Mix_PlayChannel(-1, gLow, 0);
						break;
					case SDLK_4:
						Mix_PlayChannel(-1, gScratch, 0);
						break;
					case SDLK_9:
						if (Mix_PlayingMusic() == 0) {
							Mix_PlayMusic(gMusic, -1);
						}
						else {
							if (Mix_PausedMusic() == 1) {
								Mix_ResumeMusic();
							}
							else {
								Mix_PauseMusic();
							}
						}
						break;
					case SDLK_0:
						Mix_HaltMusic();
						break;
					
				}
			}
		}*/

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				close();
				return 0;
			}

			dot.handleEvent(e);
		}

		dot.move();

		/*
		timeText.str("");

		timeText << "Miliseconds since start time " << SDL_GetTicks() - startTime;

		if (!gTimeTexture.loadFromRenderedText(timeText.str().c_str(), textColor, gRenderer, gFont)) {
			printf("Unable to render time texture!\n");
		}*/

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
		
		/*int avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		timeText.str("");
		timeText << "Average Frames per Second:  " << avgFPS;

		if (!gTimeTexture.loadFromRenderedText(timeText.str().c_str(), textColor, gRenderer, gFont)) {
			printf("Unable to render time texture!\n");
		}*/

		//clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		dot.render(gBlockTexture,gRenderer);

		//gStartPrompt.render((SCREEN_WIDTH - gStartPrompt.getWidth()) / 2, 0, gRenderer);

		//gPausePrompt.render((SCREEN_WIDTH - gStartPrompt.getWidth()) / 2, gStartPrompt.getHeight(), gRenderer);

		//gTimeTexture.render((SCREEN_WIDTH - gTimeTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTimeTexture.getHeight()) / 2, gRenderer);

		//gBaseTexture.render((SCREEN_WIDTH - gBaseTexture.getWidth()) / 2, 0, gRenderer);

		//gTimeTexture.render((SCREEN_WIDTH - gBaseTexture.getWidth()) / 2, (SCREEN_HEIGHT - gBaseTexture.getHeight()) / 2, gRenderer);

		//currentTexture->render(0, 0, gRenderer);

		SDL_RenderPresent(gRenderer);
		//++countedFrames;

		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}

	close();
	return 0;
}