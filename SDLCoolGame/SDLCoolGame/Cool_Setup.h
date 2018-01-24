#pragma once
class Cool_Setup
{
public:
	Cool_Setup(bool* quit);
	~Cool_Setup();
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480; 

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();

private:
	SDL_Window * window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
};

