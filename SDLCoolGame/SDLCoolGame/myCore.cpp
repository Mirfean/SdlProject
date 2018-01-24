#include "coreHeader.h"
#include "Main.h"

using std::cout;
using std::endl;

int main(int argc, char *args[]){

	//SDL_Init(SDL_INIT_EVERYTHING);

	CoolMain* main = new CoolMain();
	main->GameLoop();

	return 0;
}