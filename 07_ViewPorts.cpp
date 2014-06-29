/*

Using viewports

*/
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


//The window we'll be rendering to
SDL_Window* gWindow = NULL;


//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// Our renderer
SDL_Renderer* gRenderer = NULL;

SDL_Texture* loadTexture(std::string);

SDL_Rect* createRect(int x, int y, int width, int height);

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
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
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

	

	return success;
}

void close()
{
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
			SDL_Texture* texture = loadTexture("gfx/lesson9/viewport.png");

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

				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xff);

				// Clear scene

				SDL_RenderClear(gRenderer);


				// Render blue filled square


				// Top leftt viewport

				SDL_Rect topLeftViewPort = { 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_RenderSetViewport(gRenderer, &topLeftViewPort);
				SDL_RenderCopy(gRenderer, texture, NULL, NULL);

				// Top right viewport

				SDL_Rect topRightViewPort = { SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_RenderSetViewport(gRenderer, &topRightViewPort);
				SDL_RenderCopy(gRenderer, texture, NULL, NULL);

				// Bottom viewport

				SDL_Rect bottomViewPort = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
				SDL_RenderSetViewport(gRenderer, &bottomViewPort);
				SDL_RenderCopy(gRenderer, texture, NULL, NULL);

				// Update screen

				SDL_RenderPresent(gRenderer);

			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

SDL_Rect* createRect(int x, int y, int width, int height){

	SDL_Rect newRect = { x, y, width, height };
	SDL_Rect* rect = &newRect;
	return rect;
}

SDL_Texture* loadTexture(std::string path){
	SDL_Texture* texture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return texture;
}*/