/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
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

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//Loads individual image as Texture
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window we'll be rendering to
SDL_Renderer* gRenderer = NULL;

LTexture gFooTexture;
LTexture gBackgroundTexture;

SDL_Rect gSpriteClips[4];
LTexture gSpriteSheetTexture;

//Current displayed Texture
SDL_Texture* gTexture = NULL;


//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//ASK ABOUT ENUMERATORS, ALSO PUT THIS ON GITHUB FOR TOM TO SEE
//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

SDL_Texture* gKeyPressTextures[KEY_PRESS_SURFACE_TOTAL];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

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
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //THIS IS HOW YOU PUT COLOR ON THE RENDERER, putting an image on top just discards the color

				//IN THIS PART, i still dont know how to check for two different types, in this case its only a JPG and then both JPG and BMP will work, but see how to get more than
				//just two
				int imgFlags = IMG_INIT_JPG;

				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
				}
				else {
					imgFlags = IMG_INIT_PNG;
					if (!(IMG_Init(imgFlags) & imgFlags)) {
						printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
					}
					else {
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

	if (!gSpriteSheetTexture.loadFromFile("images/sprites.png", gRenderer)) {
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else {

		//Set top left sprite
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 100;
		gSpriteClips[0].h = 100;

		//Set top right sprite
		gSpriteClips[1].x = 100;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 100;
		gSpriteClips[1].h = 100;

		//Set bottom left sprite
		gSpriteClips[2].x = 0;
		gSpriteClips[2].y = 100;
		gSpriteClips[2].w = 100;
		gSpriteClips[2].h = 100;

		//Set bottom right sprite
		gSpriteClips[3].x = 100;
		gSpriteClips[3].y = 100;
		gSpriteClips[3].w = 100;
		gSpriteClips[3].h = 100;
	}

	/*
	//Loading different textures, in this case we took off the chroma key
	if (!gFooTexture.loadFromFile("images/foo.png",gRenderer)) {
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gBackgroundTexture.loadFromFile("images/background.png", gRenderer)) {
		printf("Failed to load Background texture image!\n");
		success = false;
	}
	*/

	/*
	//code for loading texture images
	gTexture = loadTexture("images/magui2.jpg");
	if (gTexture == NULL) {
		printf("Failted to load texture image!\n");
		success = false;
	}*/

	/*
	//Code for loading various images according to each key
	//Load default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("images/magui.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	//Load up surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("images/magui2.jpg");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		success = false;
	}

	//Load down surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("images/spiderman.png");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load down image!\n");
		success = false;
	}

	//Load left surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("images/left.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("images/right.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}
	*/

	return success;
}


void close()
{
	gFooTexture.free();
	gBackgroundTexture.free();

	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


//So right here we're loading the surface to an array?
SDL_Surface* loadSurface(std::string path) {

	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);

		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}


SDL_Texture* loadTexture(std::string path) {

	//The final Texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
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

			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

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
					/*
					//Code for pressing keys
					//User presses a key
					else if (e.type == SDL_KEYDOWN)
					{
						//Select surfaces based on key press
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							break;

						case SDLK_DOWN:
							//SDL_RenderCopy(gRenderer, gKeyPressTextures[KEY_PRESS_SURFACE_DOWN], NULL, NULL);
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							break;

						case SDLK_LEFT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
							break;

						case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;

						default:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}*/
				}


				//RENDERING DIFFERENT SPRITES FROM A SPRITESHEET, BANGEEEEEEER
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//top left sprite
				gSpriteSheetTexture.render(0, 0, &gSpriteClips[0], gRenderer);

				//top right sprite
				gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[1].w, 0, &gSpriteClips[1], gRenderer);

				//bottom left sprite
				gSpriteSheetTexture.render(0, SCREEN_HEIGHT - gSpriteClips[2].h, &gSpriteClips[2], gRenderer);

				//bottom right sprite
				gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[3].w, SCREEN_HEIGHT - gSpriteClips[3].h, &gSpriteClips[3], gRenderer);

				SDL_RenderPresent(gRenderer);

				/*
				//Apply the image stretched
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;

				SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &stretchRect);
				*/
				
				/*
				//Code for rendering texture images
				//SDL_RenderClear fills the screen with the color last set
				SDL_RenderClear(gRenderer);
				//this function renders the image onto the back end
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				//this function is like the updatewindowsurface but for renderer
				SDL_RenderPresent(gRenderer);
				*/

				/*
				//Code for rendering geometry
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				
				//Render pink filled quad
				SDL_Rect fillRect{ SCREEN_WIDTH / 4, SCREEN_WIDTH / 5, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(gRenderer, 255, 192, 203, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);
				
				//Render green outlined quad
				SDL_Rect outlineRect{ SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
				SDL_RenderDrawRect(gRenderer, &outlineRect);

				//Drawing a blue horizontal line
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
				SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

				//Draw vertical line of yellow dots
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 4)
				{
					SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
				}

				//Update screen
				SDL_RenderPresent(gRenderer);
				*/

				//Apply the image unscaled
				//SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

				//Update the surface
				//SDL_UpdateWindowSurface(gWindow);

				/*
				//Rendering Viewports
				SDL_RenderClear(gRenderer);

				SDL_Rect topLeftViewport;
				topLeftViewport.x = 0;
				topLeftViewport.y = 0;
				topLeftViewport.w = SCREEN_WIDTH / 2;
				topLeftViewport.h = SCREEN_HEIGHT / 2;
				SDL_RenderSetViewport(gRenderer, &topLeftViewport);

				//Render texture to screen
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				SDL_Rect topRightViewport;
				topRightViewport.x = SCREEN_WIDTH / 2;
				topRightViewport.y = 0;
				topRightViewport.w = SCREEN_WIDTH / 2;
				topRightViewport.h = SCREEN_HEIGHT / 2;
				SDL_RenderSetViewport(gRenderer, &topRightViewport);

				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				//Bottom viewport
				SDL_Rect bottomViewport;
				bottomViewport.x = 0;
				bottomViewport.y = SCREEN_HEIGHT / 2;
				bottomViewport.w = SCREEN_WIDTH;
				bottomViewport.h = SCREEN_HEIGHT / 2;
				SDL_RenderSetViewport(gRenderer, &bottomViewport);

				//Render texture to screen
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				SDL_RenderPresent(gRenderer);
				*/

				/*
				//Rendering different textures
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				gBackgroundTexture.render(0, 0, gRenderer);

				gFooTexture.render(240, 190, gRenderer);

				SDL_RenderPresent(gRenderer);
				*/
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}