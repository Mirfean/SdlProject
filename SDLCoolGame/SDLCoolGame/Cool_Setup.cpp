#include "coreHeader.h"
#include "Cool_Setup.h"

using std::cout;
using std::endl;


Cool_Setup::Cool_Setup(bool* quit)
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	
	window = NULL;
	window = SDL_CreateWindow("CoolGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "Window is null?!";
		*quit = true;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent = new SDL_Event();
}


Cool_Setup::~Cool_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* Cool_Setup::GetRenderer(){
	return renderer;
}

SDL_Event* Cool_Setup::GetMainEvent() {

	return mainEvent;
}

void Cool_Setup::Begin() {

	SDL_PollEvent(GetMainEvent());
	SDL_RenderClear(GetRenderer());

}

void Cool_Setup::End() {

	SDL_RenderPresent(GetRenderer());
}
