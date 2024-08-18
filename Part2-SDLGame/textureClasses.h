#ifndef TEXTURECLASSES_H
#define TEXTURECLASSES_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>


class LTexture {
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image from specified path
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);

	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* gFont, SDL_Renderer* gRenderer);

	//Deallocates memory
	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setBlendMode(SDL_BlendMode blending);

	void setAlpha(Uint8 alpha);

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
