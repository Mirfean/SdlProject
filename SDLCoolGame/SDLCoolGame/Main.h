#pragma once
#include "Cool_Setup.h"
#include "GameObject.h"

class CoolMain
{
public:
	CoolMain();
	~CoolMain();
	void GameLoop();
	bool CheckCollision(SDL_Rect player, SDL_Rect something);

private:
	bool quit;

	Game_Object* background;
	Game_Object* box;
	Game_Object* skulls[30];
	Game_Object* death;

	bool MoveUp;
	bool MoveDown;
	bool MoveRight;
	bool MoveLeft;

	int TCM; //TimeCheckerMovement
	int TCS; //TimeCheckerSkulls
	int TCSS; //TimeCheckerSkulls

	Game_Object* GenerateSkull();

	void MoveSkulls(int temp);

	//SDL_Texture* background;
	//SDL_Rect background_rect;
	//SDL_Texture* player_texture;
	//SDL_Rect player_texture_rect;

	Cool_Setup* cool_setup;
};
