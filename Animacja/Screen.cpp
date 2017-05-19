#include "Screen.h"



Screen::Screen():window(NULL), renderer(NULL), texture(NULL), buffer1(NULL)
{
}

void Screen::Init()
{
	//initializing buffer1 to cover full window with memory cells of Uint32 and setting it to 0
	buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	SDL_memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Okno", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void Screen::Close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	delete[] buffer1;

	SDL_Quit();
}

//Update screen with current buffer content
void Screen::Update()
{
//	buffer1[(SCREEN_WIDTH / 2 * SCREEN_HEIGHT) + (SCREEN_WIDTH / 2)] = 0xffffff00;

	//SDL stuff to update screen, i'm using buffer of Uint32 
	SDL_UpdateTexture(texture, NULL, buffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
//TODO set pixel
void Screen::SetPixel(int x, int y, unsigned int color)
{
	if (x<SCREEN_WIDTH&&y<SCREEN_HEIGHT)
	{
		buffer1[(y*SCREEN_WIDTH)+x] = color;
	}
	
}