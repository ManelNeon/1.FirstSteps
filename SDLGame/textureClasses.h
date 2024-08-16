#ifndef TEXTURECLASSES_H
#define TEXTURECLASSES_H

#include <string>
#include <SDL.h>


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
	void render(int x, int y, SDL_Renderer* gRenderer);

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
