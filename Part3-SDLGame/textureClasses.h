#ifndef TEXTURECLASSES_H
#define TEXTURECLASSES_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;

const int TOTAL_BUTTONS = 4;

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

#endif // !TEXTURECLASSES_H
