#include <SDL.h>
#include <time.h> 
#include <stdlib.h>
#include <iostream>

#include "Screen.h"
#include "Particle.h"




static const int NUMBER_OF_PARTICLES = 500;

int main(int argc, char ** argv)
{

	srand(time(NULL));

	Screen screen;

	screen.Init();

	Particle* particles = new Particle[NUMBER_OF_PARTICLES];

	//I cannot invoke constructor which takes parameters like position above so im setting it below in a loop
	for (int i = 0; i < NUMBER_OF_PARTICLES; i++)
	{
		particles[i].SetPosition(Screen::SCREEN_WIDTH/2, Screen::SCREEN_HEIGHT/2);
	}
	

	//Time (Tick) varibles
	int TimeRunning = 0, TimeLastUpdate = 0, Tick = 0;

	//For closing detection
	SDL_Event event;
	bool quit = false;

	//Animation loop
	while (!quit)
	{
		//Getting Tick(time elapsed)
		TimeLastUpdate = TimeRunning;
		TimeRunning = SDL_GetTicks();
		Tick = TimeRunning - TimeLastUpdate;
		
		for (int i = 0; i < NUMBER_OF_PARTICLES; i++)
		{
			particles[i].Update(Tick);
			screen.SetPixel(particles[i].GetPositionX(), particles[i].GetPositionY(), particles[i].GetColor());
		}

		screen.Update();

		

		//Ending animation loop if window is closed;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	
	screen.Close();
	delete[] particles;

	return 0;
}
