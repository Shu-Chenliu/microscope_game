#include "game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "StartScreen.h"
#include "editScreen.h"
#include "player.h"
#include "enemy.h"
#include <cstdlib> 
#include <ctime>   /* 時間相關函數 */
using namespace std;
player* player1=nullptr;

enemy* enemy1=nullptr;

GameObject* p1;
GameObject* p2;
GameObject* p3;
GameObject* p4;
GameObject* p5;
GameObject* money;
GameObject* ourhome;
GameObject* ourHomeBlood;
GameObject* enemyhome;
GameObject* enemyHomeBlood;
GameObject* winningSign;
SDL_Renderer* Game::renderer=nullptr;
const char* Game::pictures[9] = {
	"assets/bio1.png",
	"assets/bio2.png",
	"assets/bio3.png",
	"assets/bio4.png",
	"assets/bio5.png",
	"assets/bio6.png",
	"assets/bio7.png",
	"assets/bio8.png",
	"assets/bio9.png"
};
const char* Game::playerpic[9] = {
	"assets/p1.png",
	"assets/p2.png",
	"assets/p3.png",
	"assets/p4.png",
	"assets/p5.png",
	"assets/p6.png",
	"assets/p7.png",
	"assets/p8.png",
	"assets/p9.png",
};
const char* Game::enemypic[5] = {
	"assets/e1.png",
	"assets/e2.png",
	"assets/e3.png",
	"assets/e4.png",
	"assets/e5.png",
};
int vel[9] = {
	1,2,1,4,2,8,10,2,7
};
int attack[9] = {
	6,7,1,3,10,8,3,6,8
};
int blood[9] = {
	125,126,115,119,126,129,116,126,116
};
int price[9] = {
	250,499,351,151,405,206,206,255,475
};
StartScreen* startscreen;
editScreen* editscreen;
const Uint8* keystate = SDL_GetKeyboardState(NULL);
Game::Game() {
    count = 0;
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = 400;
	srcR.h = 200;
	destR.x = 200;
	destR.y = 90;
	destR.w = 400;
	destR.h = 200;
}
Game::~Game() {

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "subsystem initialized" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "window created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255,255, 0);//預設背景顏色
			cout << "renderer created" << endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	startscreen = new StartScreen(renderer, "edit team", "start", "black");
	editscreen = new editScreen(renderer, "black");
	money = new GameObject(count, 630, 10, 140, 45,"black");
	ourHomeBlood = new GameObject(ourhomeBlood, 550, 200, 70, 25, "black");
	enemyHomeBlood = new GameObject(enemyhomeBlood, 200, 200, 70, 25, "black");
}
void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
		if (keystate[SDL_SCANCODE_1]) {//havn't check money yet
			if (!player1&&count>=price[team[0]]) {
				player1 = new player(pictures[team[0]], 570, 400, 50, 50, vel[team[0]],attack[team[0]], blood[team[0]], price[team[0]]);
				count -= price[team[0]];
			}
		}
		if (keystate[SDL_SCANCODE_2]) {
			if (!player1 && count >= price[team[1]]) {
				player1 = new player(pictures[team[1]], 570, 400, 50, 50, vel[team[1]], attack[team[1]], blood[team[1]], price[team[1]]);
				count -= price[team[1]];
			}
		}
		if (keystate[SDL_SCANCODE_3]) {
			if (!player1 && count >= price[team[2]]) {
				player1 = new player(pictures[team[2]], 570, 400, 50, 50, vel[team[2]], attack[team[2]], blood[team[2]], price[team[2]]);
				count -= price[team[2]];
			}
		}
		if (keystate[SDL_SCANCODE_4]) {
			if (!player1 && count >= price[team[3]]) {
				player1 = new player(pictures[team[3]], 570, 400, 50, 50, vel[team[3]], attack[team[3]], blood[team[3]], price[team[3]]);
				count -= price[team[3]];
			}
		}
		if (keystate[SDL_SCANCODE_5]) {
			if (!player1 && count >= price[team[4]]) {
				player1 = new player(pictures[team[4]], 570, 400, 50, 50, vel[team[4]], attack[team[4]], blood[team[4]], price[team[4]]);
				count -= price[team[4]];
			}
		}
        break;

    case SDL_KEYUP:
        break;

    default:
        break;
    }
}
void Game::loadpicture() {
	p1 = new GameObject(pictures[team[0]], 30, 550, 140, 80);
	p2 = new GameObject(pictures[team[1]], 180, 550, 140, 80);
	p3 = new GameObject(pictures[team[2]], 330, 550, 140, 80);
	p4 = new GameObject(pictures[team[3]], 480, 550, 140, 80);
	p5 = new GameObject(pictures[team[4]], 630, 550, 140, 80);
	ourhome = new GameObject("assets/ourhome.png", 570, 200,0,0, 348, 577);
	enemyhome = new GameObject("assets/enemyhome.png", 50, 200,0,0, 348, 577);
}
void Game::update() {
    count++;
	t++;
	if (t % 300==0) {
		if (!enemy1) {
			srand((unsigned)time(NULL));
			int a = rand() % 5;
			enemy1 = new enemy(enemypic[a], 90, 400, 494, 454, 0.1, 0.1, 3, 8, 200);
		}
	}
	money->update(count);
	if (enemy1) {
		enemy1->update();
		if (enemy1->getxpos() >= 570) {
			ourhomeBlood -= enemy1->getAttack();
		}
	}
	if (player1) {
		player1->update();
		if (player1->getxpos() <= 150) {
			enemyhomeBlood -= player1->getAttack();
		}
	}
	if (player1 && enemy1) {
		if (player1->getxpos() - enemy1->getxpos() < 50) {
			enemy1->setmoving(false);
			player1->setmoving(false);
		}
		if (enemy1->getmoving() == false && enemy1->getxpos() < 570) {
			enemy1->beAttack(player1->getAttack());
			cout << enemy1->getBlood();
			if (enemy1->getBlood() <= 0) {
				enemy1->~enemy();
				enemy1 = nullptr;
				player1->setmoving(true);
			}
		}
		if (player1->getmoving() == false && player1->getxpos() > 150) {
			player1->beAttack(enemy1->getAttack());
			if (player1->getBlood() <= 0) {
				player1->~player();
				player1 = nullptr;
				enemy1->setmoving(true);
			}
		}
	}
	ourHomeBlood->update(ourhomeBlood);
	enemyHomeBlood->update(enemyhomeBlood);
}
void Game::render() {
    SDL_RenderClear(renderer);
	p1->render();
	p2->render();
	p3->render();
	p4->render();
	p5->render();
	money->render();
	ourhome->render();
	enemyhome->render();
	if (enemy1) {
		enemy1->render();
	}
	ourHomeBlood->render();
	enemyHomeBlood->render();
	if (player1) {
		player1->render();
	}
	SDL_RenderCopy(renderer, objTexture1, &srcR, &destR);
    SDL_RenderPresent(renderer);
	if (isRunning == false) {
		SDL_Delay(3000);//暫停贏家畫面
	}
}
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    cout << "Game is cleaned" << endl;
}
bool Game::running() {
	return isRunning;
}
void Game::displayStartScreen() {
	startscreen->handleEvents(keystate, isStart, isEdit);
	startscreen->update();
	startscreen->render();
}
void Game::displayEditScreen() {
	editscreen->handleEvents(keystate, isStart, isEdit,team);
	editscreen->update();
	editscreen->render();
}
void Game::end() {
	//cout << "end" << endl;
	if (ourhomeBlood <= 0) {
		objTexture1 = TextureManager::loadFont("You lose...", "black");
		isRunning = false;
	}
	else if (enemyhomeBlood <= 0) {
		objTexture1 = TextureManager::loadFont("You win!!!", "black");
		isRunning = false;
	}
	return;
}