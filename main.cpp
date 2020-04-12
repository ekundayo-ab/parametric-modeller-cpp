//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

bool exit()
{
	SDL_Quit();
	return 0;
}

int main(int argc, char* argv[]) {
	SDL_Window *window;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 480, SDL_WINDOW_OPENGL);

	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	int scanCode = 0;

	SDL_Event event;

	while (scanCode != SDL_SCANCODE_C) {
    while (SDL_PollEvent(&event)) {
			std::cout << event.type << "\n";
			scanCode = event.key.keysym.scancode;
        /* handle your event here */
    }
    /* do some other stuff here -- draw your app, etc. */
	}

	SDL_DestroyWindow(window);

	exit();
}