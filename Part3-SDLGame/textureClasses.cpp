#include "textureClasses.h"
#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "globalVariables.h"

const int WALKING_ANIMATION_FRAMES = 4;

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

bool LTexture::loadFromFile(std::string path, SDL_Renderer* gRenderer) {
	//Get rid of previous texture
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		//Color Key Image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else {
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont) {

	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	if (mTexture == NULL) {
		printf("Unable to create texutre from rendered text! SDL_Error : %s\n", SDL_GetError());
		SDL_FreeSurface(textSurface);
		return false;
	}

	mWidth = textSurface->w;
	mHeight = textSurface->h;

	SDL_FreeSurface(textSurface);

	return true;
}

void LTexture::free() {

	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
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

//Dot Definitions

Dot::Dot() {
	mPosX = 0;
	mPosY = 0;

	mVelX = 0;
	mVelY = 0;
}

void Dot::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
			case SDLK_UP: mVelY -= DOT_VEL; break;
			case SDLK_DOWN: mVelY += DOT_VEL; break;
			case SDLK_LEFT: mVelX -= DOT_VEL; break;
			case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
			case SDLK_UP: mVelY += DOT_VEL; break;
			case SDLK_DOWN: mVelY -= DOT_VEL; break;
			case SDLK_LEFT: mVelX += DOT_VEL; break;
			case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}

void Dot::move() {
	mPosX += mVelX;

	if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH)) {
		mPosX -= mVelX;
	}

	mPosY += mVelY;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT))
	{
		//Move back
		mPosY -= mVelY;
	}
}

void Dot::render(LTexture& imageTexture, SDL_Renderer* gRenderer) {
	imageTexture.render(mPosX, mPosY, gRenderer);
}