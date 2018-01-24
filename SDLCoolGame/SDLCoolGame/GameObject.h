#pragma once
#include "coreHeader.h"
class Game_Object
{
public:
	Game_Object(SDL_Renderer* renderer,const char* path, int xx, int yy, int hh, int ww);
	~Game_Object();

	SDL_Texture* GetTexture();
	SDL_Rect GetRect();

	void SetRectX(int x);
	void SetRectY(int y);
	void SetRectH(int h);
	void SetRectW(int w);

private:

	SDL_Texture* texture;
	SDL_Rect rect;
};

