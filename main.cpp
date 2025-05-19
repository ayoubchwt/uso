#include "Game.h"
int main(int argc , char *argv[]) {
	Game* game = new Game();
	if (!game->Init("SDL osu!", 1280, 720, false)) {
		SDL_Quit;
		return -1; 
	}
	while (game->IsRunning()) {
		game->handleEvent();
		game->Update();
		game->Render();
	}
	return 0; 
}
