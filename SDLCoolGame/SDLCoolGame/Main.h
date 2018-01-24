#pragma once
#include "Cool_Setup.h"
#include "GameObject.h"

class CoolMain
{
public:
	CoolMain();
	~CoolMain();
	void GameLoop();

private:
	bool quit;
	Game_Object* backgroundGO;
	Game_Object* box;

	//SDL_Texture* background;
	//SDL_Rect background_rect;
	//SDL_Texture* player_texture;
	//SDL_Rect player_texture_rect;

	Cool_Setup* cool_setup;
};
