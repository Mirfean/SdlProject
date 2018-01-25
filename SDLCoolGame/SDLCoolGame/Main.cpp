#include "coreHeader.h"
#include "Main.h"
#include "GameObject.h"
#include <cstdlib>
using std::cout;
using std::rand;

CoolMain::CoolMain()
{
	quit = false;
	cool_setup = new Cool_Setup(&quit);
	TCM = SDL_GetTicks();
	TCS = SDL_GetTicks();
	TCSS = SDL_GetTicks();


	background = new Game_Object(cool_setup->GetRenderer(), "Resources/mapa3.bmp", 0, 0, cool_setup->SCREEN_HEIGHT, cool_setup->SCREEN_WIDTH);
	box = new Game_Object(cool_setup->GetRenderer(), "Resources/Hero.bmp", 320, 240, 24,24);
	death = new Game_Object(cool_setup->GetRenderer(), "Resources/death.bmp", 0,0,16,16);
	//skulls[0] = new Game_Object(cool_setup->GetRenderer(), "Resources/death.bmp", 32, 0, 16, 16);


	MoveUp = false;
	MoveDown = false;
	MoveRight = false;
	MoveLeft = false;

}

CoolMain::~CoolMain()
{
	SDL_Quit();
}


void CoolMain::GameLoop() {

	bool newSkull = false;
	int lolz = 0;
	int jump = 0;
	int blockade = 10;
	while (!quit && cool_setup->GetMainEvent()->type != SDL_QUIT) {

		cool_setup->Begin();

		switch (cool_setup->GetMainEvent()->type) {

			case SDL_KEYUP:
				switch (cool_setup->GetMainEvent()->key.keysym.sym)
				{
				case SDLK_a:
					MoveLeft = false;
					break;
				case SDLK_d:
					MoveRight = false;
					break;
				case SDLK_w:
					MoveUp = false;
					break;
				case SDLK_s:
					MoveDown = false;
					break;
				}
				break;

			case SDL_KEYDOWN:
				switch (cool_setup->GetMainEvent()->key.keysym.sym)
				{
				case SDLK_a:
					MoveLeft = true;
					break;
				case SDLK_d:
					MoveRight = true;
					break;
				case SDLK_w:
					MoveUp = true;
					break;
				case SDLK_s:
					MoveDown = true;
					break;
				//default: break;
				case SDLK_5:
					box->GetPhysics().inc(2);
					blockade=blockade+5;
					newSkull = true;
					break;
				}
				break;

			//default: break;
		}

		if (TCSS + 15 < SDL_GetTicks()) {

			for (int u=0; u<lolz; u++) {
				//skulls[u]->GetPhysics().inc(4);
			}
			TCSS = SDL_GetTicks();
		}

		//Create new skull
		if (TCS + 1000 < SDL_GetTicks()) {

			if(lolz<blockade){
				skulls[lolz] = GenerateSkull();
				lolz++;
			}
			TCS = SDL_GetTicks();
		}
		
		if (TCM + 15 < SDL_GetTicks())
		{	

			MoveSkulls(lolz-1);
			if (MoveDown) {
				box->MoveY(box->GetPhysics().GetVel());
				box->SetTexture(cool_setup->GetRenderer(), "Resources/Herodol.bmp");
			}
			if (MoveUp) {
				box->MoveY(-box->GetPhysics().GetVel());
				box->SetTexture(cool_setup->GetRenderer(), "Resources/Herogora.bmp");
			}
			if (MoveLeft) {
				box->MoveX(-box->GetPhysics().GetVel());
				box->SetTexture(cool_setup->GetRenderer(), "Resources/Hero.bmp");
			}
			if (MoveRight) {
				box->MoveX(box->GetPhysics().GetVel());
				box->SetTexture(cool_setup->GetRenderer(), "Resources/Heroprawo.bmp");
			}
			TCM = SDL_GetTicks();
		}

		for (int t = 0; t <lolz; t++) {
			if (CheckCollision(box->GetRect(), skulls[t]->GetRect())) {
				quit = true;
			}
		}
		
		background->UpdatePosition(cool_setup->GetRenderer());
		box->UpdatePosition(cool_setup->GetRenderer());

		//Make skulls
		for (int t = 0; t <lolz; t++) {
			skulls[t]->UpdatePosition(cool_setup->GetRenderer());
		}
		death->UpdatePosition(cool_setup->GetRenderer());
		
		cool_setup->End();
	}

}

bool CoolMain::CheckCollision(SDL_Rect player, SDL_Rect something) {

	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = player.x;
	rightA = player.x + player.w;
	topA = player.y;
	bottomA = player.y + player.h;

	//Calculate the sides of rect B
	leftB = something.x;
	rightB = something.x + something.w;
	topB = something.y;
	bottomB = something.y + something.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}
	return true;
}

Game_Object* CoolMain::GenerateSkull() {

	int tempX = 0;
	int tempY = 0;
	int side = (rand() % 4) + 1;
	switch (side) {

	case 1: {	//north
		tempX = (rand() % 641) + 0;
		tempY = -20;
		Game_Object* temp = new Game_Object(cool_setup->GetRenderer(), "Resources/death2.bmp", tempX, tempY, 24, 24);
		return temp;
		break;
	}
	case 2: {	//east
		tempX = cool_setup->SCREEN_WIDTH + 20;
		tempY = (rand() % 481) + 0;
		Game_Object* temp = new Game_Object(cool_setup->GetRenderer(), "Resources/death2.bmp", tempX, tempY, 24, 24);
		return temp;
		break;
	}
	case 3: {	//south
		tempX = (rand() % 641) + 0;
		tempY = cool_setup->SCREEN_HEIGHT + 20;
		Game_Object* temp = new Game_Object(cool_setup->GetRenderer(), "Resources/death2.bmp", tempX, tempY, 24, 24);
		return temp;
		break;
	}
	case 4: {	//west
		tempX = -20;
		tempY = (rand() % 481) + 0;
		Game_Object* temp = new Game_Object(cool_setup->GetRenderer(), "Resources/death2.bmp", tempX, tempY, 24, 24);
		return temp;
		break;
	}
			break;
	}

	Game_Object* temp = new Game_Object(cool_setup->GetRenderer(), "Resources/death.bmp", tempX, tempY, 16, 16);

	return temp;
}

void CoolMain::MoveSkulls(int amount) {

	for (int t = 0; t <=amount; t++) {
		int random = (rand() % 3) - 1;
		if (skulls[t]->GetRect().x < 0) {
			skulls[t]->onMap = false;
			skulls[t]->MoveY(skulls[t]->GetPhysics().GetVel()*random);
			skulls[t]->MoveX(skulls[t]->GetPhysics().GetVel()*4);
		}
		if (skulls[t]->GetRect().y < 0) {
			skulls[t]->onMap = false;
			skulls[t]->MoveY(skulls[t]->GetPhysics().GetVel()*4);
			skulls[t]->MoveX(skulls[t]->GetPhysics().GetVel()*random);

		}
		if (skulls[t]->GetRect().x > 640){
			skulls[t]->onMap = false;
			skulls[t]->MoveY(skulls[t]->GetPhysics().GetVel()*random);
			skulls[t]->MoveX(-skulls[t]->GetPhysics().GetVel()*4);
		}
		if (skulls[t]->GetRect().y > 480) {
			skulls[t]->onMap = false;
			skulls[t]->MoveY(-skulls[t]->GetPhysics().GetVel()*4);
			skulls[t]->MoveX(skulls[t]->GetPhysics().GetVel()*random);
		}
		if (skulls[t]->GetRect().y <= 480 && skulls[t]->GetRect().y >= 0 && skulls[t]->GetRect().x <= 640 && skulls[t]->GetRect().x >= 0) {
			if (!skulls[t]->onMap) {

					random = (rand() % 3) - 1;
					skulls[t]->myX = random;
					random = (rand() % 3) - 1;
					skulls[t]->myY = random;
					if (!skulls[t]->myX == 0 && !skulls[t]->myY == 0) {
						skulls[t]->onMap = true;
					}
					
			}
			skulls[t]->MoveY(skulls[t]->GetPhysics().GetVel()*skulls[t]->myY);
			skulls[t]->MoveX(skulls[t]->GetPhysics().GetVel()*skulls[t]->myX);

			
		}

	}

}