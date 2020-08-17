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
	SDL_Renderer* renderer = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	int windowCreationRes = 0;
	windowCreationRes = SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

	if (windowCreationRes != 0) {
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	bool quitApp = false;
	SDL_Event event;

	while (!quitApp) {
    while (SDL_PollEvent(&event)) {
			if ((event.window.event == SDL_WINDOWEVENT_CLOSE) || event.type == SDL_QUIT) {
				quitApp = true;
			}

			SDL_SetRenderDrawColor(renderer, 246, 246, 246, 255);
			SDL_RenderClear(renderer);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_GL_ACCUM_BLUE_SIZE);
			SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
			SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
			SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
			SDL_RenderPresent(renderer);
    }
	}


	SDL_DestroyWindow(window);

	exit();
}