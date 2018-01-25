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

/*Game_Object::Game_Object(SDL_Renderer* renderer, const char* path, int xx, int yy, int hh, int ww, bool xplus, bool yplus)
{
	texture = NULL;
	texture = IMG_LoadTexture(renderer, path);
	if (texture == NULL) {

		cout << "Game object not found!";
	}
	rect.x = xx;
	rect.y = yy;
	rect.h = hh;
	rect.w = ww;

}*/


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

void Game_Object::SetTexture(SDL_Renderer* renderer,const char* path) {

	texture = IMG_LoadTexture(renderer, path);
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

Physics Game_Object::GetPhysics() {
	return physics;
}

void Game_Object::UpdatePosition(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer,texture,NULL,&GetRect());
}

void Game_Object::MoveX(int tempX) {
	SetRectX(rect.x + tempX);
}

void Game_Object::MoveY(int tempY) {
	SetRectY(rect.y + tempY);
}