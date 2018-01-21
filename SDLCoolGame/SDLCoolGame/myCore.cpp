#include "coreHeader.h"
using std::cout;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char *args[]){

	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	window = SDL_CreateWindow("CoolGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (window == NULL) {
		cout << "Something went wrong :(";
		return 0;
	}

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event* mainEvent = new SDL_Event();

	SDL_Texture* background = NULL;
	background = IMG_LoadTexture(renderer, "Resources/SDLjestSuper.bmp");

	SDL_Rect texture_rect;
	texture_rect.x = 0;
	texture_rect.y = 0;
	texture_rect.h = SCREEN_HEIGHT; 
	texture_rect.w = SCREEN_WIDTH; 

	SDL_Texture* myBox = NULL;
	myBox = IMG_LoadTexture(renderer, "Resources/Box.bmp");

	SDL_Rect myBox_rect;
	myBox_rect.x = 300;
	myBox_rect.y = 250;
	myBox_rect.h = 40;
	myBox_rect.w = 40;




	//Core of the core
	while (!quit && mainEvent->type != SDL_QUIT) {

		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);

		
		SDL_RenderCopy(renderer, background, NULL, &texture_rect);
		SDL_RenderCopy(renderer, myBox, NULL, &myBox_rect);

		SDL_RenderPresent(renderer);

	}





	//End this suffering
	//SDL_Delay(2000);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(myBox);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
	SDL_Quit();
	return 0;
}