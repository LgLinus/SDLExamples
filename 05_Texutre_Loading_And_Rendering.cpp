/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
/*
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

// Load a texture
SDL_Texture* loadTexture(std::string);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

// Texture
SDL_Texture* gTexture = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// Our renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for the window
			gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL){
				printf("Renderer failed to load %s\n", SDL_GetError());
				success = false;
			}
			else{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				//Initialize PNG loading
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					//Get window surface
					gScreenSurface = SDL_GetWindowSurface(gWindow);
				}
			}
		
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	// LOad png texture

	gTexture = loadTexture("gfx/lesson6/loaded.png");
	if (gTexture == NULL){
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
}

void close()
{
	// Destroy image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				// Clear scene

				SDL_RenderClear(gRenderer);

				// Render texture to screen
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				// Update screen

				SDL_RenderPresent(gRenderer);
				
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

SDL_Texture* loadTexture(std::string path){
	SDL_Texture* newTexture = NULL;

	// Load image at specified path

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		printf("Failed to load surface at given path %s", path.c_str());
	}
	else{
		// Create texture
		newTexture = SDL_CreateTextureFromSurface(gRenderer,loadedSurface);
		if (newTexture == NULL){
			printf("Error creating texture from surface at path %s", path.c_str());
		}

		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}*/