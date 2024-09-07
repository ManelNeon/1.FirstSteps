#include "textureClasses.h"
#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

//Texture Definitions
LTexture::LTexture() {
	//initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture() {
	//deallocate
	free();
}

bool LTexture::loadFromFile(std::string path) {
	//Get rid of previous texture
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError());

		return false;
	}

	//Color Key Image
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

	if (newTexture == NULL) {
		printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

		SDL_FreeSurface(loadedSurface);

		return false;
	}
	
	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free() {

	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
	SDL_Rect renderQuad{ x, y , mWidth , mHeight };

	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx( gRenderer, mTexture , clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth() {
	return mWidth;
}

int LTexture::getHeight() {
	return mHeight;
}


//Block Definitions
LBlock::LBlock() {
	mPosX = 0;
	mPosY = 0;

	isFalling = true;

	column = 0;
	row = 0;
}

void LBlock::handleEvent(SDL_Event& e) {

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {;
			case SDLK_RIGHT:
				if (!digitalBoard[row*(column + 1)]) {
					column++;
					mPosX += 60;
				}
				break;
			case SDLK_LEFT: 
				if (!digitalBoard[row*(column - 1)]) {
					column--;
					mPosX -= 60;
				}
				break;
			case SDLK_DOWN:
				if (!digitalBoard[(row + 1) * column]) {
					row++;
					mPosY += 60;
				}
		}
	}
}

void LBlock::move() {

	if (!digitalBoard[(row + 1) * column]) {
		row++;
		mPosY += 60;
	}

	if (digitalBoard[(row + 1) * column] && isFalling) {
		isFalling = false;
	}
}

void LBlock::render(LTexture* blockTexture) {
	blockTexture->render(mPosX, mPosY);
}

bool LBlock::getIsFalling() {
	return isFalling;
}

int LBlock::getColumn() {
	return column;
}

int LBlock::getRow() {
	return row;
}

//Timer Definitions
LTimer::LTimer() {

	mStartTicks = 0;
	mPausedTicks = 0;

	mPaused = false;
	mStarted = false;
}

void LTimer::start() {
	mStarted = true;

	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void LTimer::stop() {
	mStarted = false;

	mPaused = false;

	mStartTicks = 0;
	mPausedTicks = 0;
}

void LTimer::pause() {
	if (mStarted && !mPaused) {
		mPaused = true;

		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void LTimer::unpause() {
	if (mStarted && mPaused) {
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

Uint32 LTimer::getTicks() {

	if (mStarted) {
		if (mPaused) {
			return mPausedTicks;
		}
		else {
			return SDL_GetTicks() - mStartTicks;
		}
	}

	return 0;
}

bool LTimer::isStarted() {
	return mStarted;
}

bool LTimer::isPaused() {
	return mPaused && mStarted;
}