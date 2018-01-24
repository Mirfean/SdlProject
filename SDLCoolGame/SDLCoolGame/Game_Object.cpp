#include "GameObject.h"
using std::cout;


Game_Object::Game_Object(SDL_Renderer* renderer,const char* path, int xx, int yy, int hh, int ww)
{
	texture = NULL;
	texture = IMG_LoadTexture(renderer,path);
	if (texture == NULL) {

		cout << "Game object not found!";
	}
	rect.x = xx;
	rect.y = yy;
	rect.h = hh;
	rect.w = ww;
}

Game_Object::~Game_Object()
{
	SDL_DestroyTexture(texture);
}

SDL_Texture* Game_Object::GetTexture()
{
	return texture;
}
SDL_Rect Game_Object::GetRect() 
{
	return rect;
}

void Game_Object::SetRectX(int x)
{
	rect.x = x;
}

void Game_Object::SetRectY(int y)
{
	rect.y = y;
}
void Game_Object::SetRectH(int h)
{
	rect.h = h;
}
void Game_Object::SetRectW(int w)
{
	rect.w = w;
}
