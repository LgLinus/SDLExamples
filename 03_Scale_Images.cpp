/*
Draws 2 images to the screen, and closes the window by pressing on the X

*New:

-Images can stretch (check loadSurface) (sdl_blitScaled())
*/
/*
#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Key press surface constants
enum KeyPressSurfaces{
	KEY_PRESS_SURFACE_DEFAULT, // = 0
	KEY_PRESS_SURFACE_UP, /// = 1
	KEY_PRESS_SURFACE_DOWN, // = 2
	KEY_PRESS_SURFACE_LEFT, // = 3
	KEY_PRESS_SURFACE_RIGHT, // = 4
	KEY_PRESS_SURFACE_TOTAL // = 5
};

// Initialize sdl
bool init();

// Load media
bool loadMedia();

// Close app
void close();

// Load individual image
SDL_Surface* loadSurface(std::string path);

SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

SDL_Window* gWindow = NULL;
SDL_Rect locationImage; // Position image
// Surface of the window
SDL_Surface* gScreenSurface = NULL;

int main(int argc, char* args[]){
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	loadMedia();

	bool quit = false;
	// Event handler
	SDL_Event e;

	locationImage.x = 10;
	locationImage.y = 0;
	locationImage.w = 200;
	locationImage.h = 250;

	gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
	// APply current image
	SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &locationImage);
	// UPdate surface

	SDL_UpdateWindowSurface(gWindow);
	// Don't close the window untill user presses on the x
	while (!quit){
		while (SDL_PollEvent(&e) != 0){ // Pop the events
			if (e.type == SDL_QUIT){ // If x pressed
				quit = true; // Exit loop
			}
			// User presses key
			else if (e.type == SDL_KEYDOWN){

				// Select surfaces based on key press
				switch (e.key.keysym.sym){
				case SDLK_UP:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
					locationImage.y -= 5;
					break;
				case SDLK_DOWN:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					locationImage.y += 5;
					break;
				case SDLK_RIGHT:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
					locationImage.x += 5;
					break;
				case SDLK_LEFT:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
					locationImage.x -= 5;
					break;
				default:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
				}

				// APply current image
				SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &locationImage);

				// UPdate surface

				SDL_UpdateWindowSurface(gWindow);
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
	gCurrentSurface = NULL;
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

/* initialize an image with the given path
SDL_Surface* loadImage(std::string path)
{
SDL_Surface* gSurface = NULL;
gSurface = SDL_LoadBMP(path);
if (gSurface == NULL){
printf("Unable to load image %s! SDL Error: %s\n", "%s", SDL_GetError(), path);
}

return gSurface;
}

// Load all our media
bool loadMedia(){
	bool success = true;


	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("gfx/lesson4/default.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL){
		printf("Failed to load default image!\n");
		success = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("gfx/lesson4/down.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN == NULL]){
		printf("failed to load down image\n");
		success = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("gfx/lesson4/up.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP == NULL]){
		printf("failed to load up image\n");
		success = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("gfx/lesson4/right.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT == NULL]){
		printf("failed to load right image\n");
		success = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("gfx/lesson4/left.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT == NULL]){
		printf("failed to load left image\n");
		success = false;
	}
	return success;
}

// Loads an image and converts it into a surface with the correct format (ex. 24/32bit)
SDL_Surface* loadSurface(std::string path){
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL){
		printf("Unable to load image %s", path);
	}
	else{
		// Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL){
			printf("Unable to optimize loaded image %s", path);
		}

		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}*/