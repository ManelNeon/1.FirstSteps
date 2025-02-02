#include "textureClasses.h"
#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


const int WALKING_ANIMATION_FRAMES = 4;

LTexture::LTexture() {
	//initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
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

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* gFont, SDL_Renderer* gRenderer) {
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else {
		mTexture = SDL_CreateTextureFromSurface(gRenderer,textSurface);
		if (mTexture == NULL) {
			printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}

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

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
	//Modulate texture
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
	SDL_Rect renderQuad{ x , y , mWidth , mHeight };

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

void LTexture::setPosition(int x, int y) {
	mPosition.x = x;
	mPosition.y = y;
}

void LTexture::handleEvent(SDL_Event* e) {
	//if mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < mPosition.x) {
			inside = false;
		}
		else if (x > mPosition.x + BUTTON_WIDTH) {
			inside = false;
		}
		else if (y < mPosition.y) {
			inside = false;
		}
		else if (y > mPosition.y + BUTTON_HEIGHT) {
			inside = false;
		}
		if (!inside) {
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else {
			switch (e->type) {
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;
				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;
				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;
			}
		}
	}
}

SDL_Point LTexture::getPosition() {
	return mPosition;
}

LButton::LButton() {
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition(int x, int y) {
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e) {
	//if mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < mPosition.x) {
			inside = false;
		}
		else if (x > mPosition.x + BUTTON_WIDTH) {
			inside = false;
		}
		else if (y < mPosition.y) {
			inside = false;
		}
		else if (y > mPosition.y + BUTTON_HEIGHT) {
			inside = false;
		}
		if (!inside) {
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else {
			switch (e->type) {
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;
			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}

void LButton::render(LTexture* currentTexture, SDL_Renderer* gRenderer, SDL_Rect* gSpriteClip) {
	currentTexture->render(mPosition.x, mPosition.y, gRenderer, gSpriteClip);
}