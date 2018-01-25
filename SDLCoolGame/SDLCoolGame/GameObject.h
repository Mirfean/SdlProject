#pragma once
#include "coreHeader.h"
#include "Physics.h"
class Game_Object
{
public:
	Game_Object(SDL_Renderer* renderer,const char* path, int xx, int yy, int hh, int ww);
	~Game_Object();

	SDL_Texture* GetTexture();
	SDL_Rect GetRect();

	void SetTexture(SDL_Renderer* renderer,const char* path);
	void SetRectX(int x);
	void SetRectY(int y);
	void SetRectH(int h);
	void SetRectW(int w);
	Physics GetPhysics();
	void UpdatePosition(SDL_Renderer* renderer);
	void MoveX(int x);
	void MoveY(int x);
	int myX;
	int myY;
	bool onMap;

private:

	SDL_Texture* texture;
	SDL_Rect rect;
	Physics physics;
	
};

