#pragma once
#include "GameObject.h"
class player:public GameObject
{
public:
	player(const char* texturesheet, int x, int y, int w, int h,int vel,int attack,int blood,int price);
	~player();
	void update();
	void render();
	bool getAlive() {
		return alive;
	}
	int getAttack() {
		return attack;
	}
	int getBlood() {
		return blood;
	}
	void setmoving(bool move) {
		moving = move;
	}
	bool getmoving() {
		return moving;
	}
	void beAttack(int a) {
		blood -= a;
	}
private:
	int vel;
	int attack;
	int blood;
	bool alive;
	bool moving;
	int price;
};

