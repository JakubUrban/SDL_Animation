#pragma once

#include <SDL.h>

class Screen
{
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	Uint32* buffer1;

public:
	Screen();

	void Init();
	void Close();
	void Update();
	void SetPixel();
};


