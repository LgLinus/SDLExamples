/*
	Draws 2 images to the screen, and closes the window by pressing on the X



	*//*

#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
bool quit = false;

// Event handler
SDL_Event e;

// Initialize sdl
bool init();

// Load media
bool loadMedia();

// Close app
void close();


SDL_Surface* initImage(char[]);

SDL_Window* gWindow = NULL;

// Surface of the window
SDL_Surface* gScreenSurface = NULL;

// Image to load and show
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gSquare = NULL;

int main(int argc, char* args[]){

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{

		gHelloWorld = initImage("gfx/helloworld.bmp");
		gSquare = initImage("gfx/square.bmp");
		if (gHelloWorld != NULL){
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_BlitSurface(gSquare, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
		}
	}

	// Don't close the window untill user presses on the x
	while (!quit){
		while (SDL_PollEvent(&e) != 0){ // Pop the events
			if (e.type == SDL_QUIT){ // If x pressed
				quit = true; // Exit loop
			}
		}
	}

	close();

	return 0;
}

bool init(){
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial Hello world", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return  success;
}


void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

// initialize an image with the given path
SDL_Surface* initImage( char path[])
{
	SDL_Surface* gSurface = NULL;
	gSurface = SDL_LoadBMP(path);
	if (gSurface == NULL){
		printf("Unable to load image %s! SDL Error: %s\n", "%s", SDL_GetError(),path);
	}

	return gSurface;
}


// Old function
bool loadMedia(){
	bool succsess = true;

	gHelloWorld = SDL_LoadBMP("gfx/helloworld.bmp");
	if (gHelloWorld == NULL){
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		succsess = false;
	}
	return succsess;
}*/