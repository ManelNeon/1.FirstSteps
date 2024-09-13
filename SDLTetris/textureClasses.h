#ifndef TEXTURECLASSES_H
#define TEXTURECLASSES_H

//SDL libraries
#include <SDL.h>

//Standard Libraries
#include <string>

//Header Files
#include "constantVariables.h"

class LTexture {
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image from specified path
	bool loadFromFile(std::string path);

	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	//Deallocates memory
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0 , SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

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

class LBlock{
public:
	LBlock();

	static const int OBJECT_WIDTH = 60;
	static const int OBJECT_HEIGHT = 60;

	static const int OBJECT_VEL = 1;

	void handleEvent(SDL_Event& e);

	void move();
	
	void moveDown();

	void render(LTexture* blockTexture);

	bool getIsFalling();

	int getColumn();

	int getRow();

private:
	int mPosX, mPosY;
	
	bool isFalling;

	int column;

	int row;
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
#endif // !TEXTURECLASSES_H