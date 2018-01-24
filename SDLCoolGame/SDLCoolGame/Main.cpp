#include "coreHeader.h"
#include "Main.h"
#include "GameObject.h"
using std::cout;

CoolMain::CoolMain()
{
	quit = false;
	cool_setup = new Cool_Setup(&quit);

	backgroundGO = new Game_Object(cool_setup->GetRenderer(), "Resources/SDLjestSuper.bmp", 0, 0, cool_setup->SCREEN_HEIGHT, cool_setup->SCREEN_WIDTH);
	box = new Game_Object(cool_setup->GetRenderer(), "Resources/Box.bmp", 320, 240, 40,40);

	/*background = NULL;
	background = IMG_LoadTexture(cool_setup->GetRenderer(), "Resources/SDLjestSuper.bmp");
	if (background == NULL) {

		cout << "background not found!";
	}
	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.h = cool_setup->SCREEN_HEIGHT;
	background_rect.w = cool_setup->SCREEN_WIDTH;*/


	/*player_texture = NULL;
	player_texture = IMG_LoadTexture(cool_setup->GetRenderer(), "Resources/Box.bmp");
	if (&player_texture == NULL) {

		cout << "player texture not found!";
	}
	player_texture_rect.x = 300;
	player_texture_rect.y = 250;
	player_texture_rect.h = 40;
	player_texture_rect.w = 40;*/

}

CoolMain::~CoolMain()
{
	//backgroundGO->~Game_Object;
	//box->~Game_Object;
	//SDL_DestroyTexture(background);
	//SDL_DestroyTexture(player_texture);
	SDL_Quit();

}


void CoolMain::GameLoop() {

	int ten = 0;
	while (!quit && cool_setup->GetMainEvent()->type != SDL_QUIT) {

		cool_setup->Begin();
		
		if (ten >= 10) {
			box->SetRectX(box->GetRect().x + 1);
			ten = 0;
		}
		
		SDL_RenderCopy(cool_setup->GetRenderer(), backgroundGO->GetTexture(), NULL, &backgroundGO->GetRect());
		SDL_RenderCopy(cool_setup->GetRenderer(), box->GetTexture(), NULL, &box->GetRect());
		ten++;
		
		
		cool_setup->End();
	}

}