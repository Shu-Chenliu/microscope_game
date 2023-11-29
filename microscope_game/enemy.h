#pragma once
#include "GameObject.h"
class enemy :public GameObject
{
public:
	enemy(const char* texturesheet, int x, int y, int w, int h,double ww,double hh, int vel, int attack, int blood);
	~enemy();
	void update();
	void render();
	bool getAlive() {
		return alive;
	}
	int getBlood() {
		return blood;
	}
	int getAttack() {
		return attack;
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
};

