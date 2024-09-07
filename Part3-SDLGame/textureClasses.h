#ifndef TEXTURECLASSES_H
#define TEXTURECLASSES_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class LTexture {
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image from specified path
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);

	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont);

	//Deallocates memory
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, double angle = 0.0 , SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

};

class LTimer {
public:
	LTimer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

private:
	Uint32 mStartTicks;

	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;
};

class Dot {
public:
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	static const int DOT_VEL = 10;

	Dot();

	void handleEvent(SDL_Event& e);

	void move();

	void render(LTexture& imageTexture, SDL_Renderer* gRenderer);

private:
	int mPosX, mPosY;

	int mVelX, mVelY;
};

#endif // !TEXTURECLASSES_H
