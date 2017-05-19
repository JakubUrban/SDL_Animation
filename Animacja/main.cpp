#include <SDL.h>
#include "Screen.h"

int main(int argc, char ** argv)
{

	Screen screen;

	screen.Init();

	//For closing detection
	SDL_Event event;
	bool quit = false;

	//Animation loop
	while (!quit)
	{

		screen.Update();

		//Ending animation loop if window is closed;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	
	screen.Close();

	return 0;
}
