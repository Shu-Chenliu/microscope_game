#include "game.h"
int main(int argc, char *argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Game* game = new Game();
	game->init("micro", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->startMode()) {
		game->displayStartScreen();
		while (game->editMode()) {
			game->displayEditScreen();
		}
	}
	game->loadpicture();
	while (game->running()) {
		frameStart = SDL_GetTicks();//�^�ǵ{������ɶ�
		game->handleEvent();
		game->update();
		game->end();//check if someone win
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);//���H���o�󶶺Z
		}
	}
	game->clean();
	return 0;
}