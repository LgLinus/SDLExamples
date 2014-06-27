/*

// Creates a SDL window with the given size, and background color in the RGB format.

#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char*args[]){
	
	// Window to render too
	SDL_Window* window = NULL;

	// surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//initialize SDL (return -1 if error)
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize! SDL_Error:%s\n", SDL_GetError());
	}
	else{

		// Create window
		window = SDL_CreateWindow("SDL Tutorial HELLO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL){
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else{
			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			// FIll the surface
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(
				screenSurface->format, 0x00, 0xAF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(3000);
		}
	}
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;

}*/