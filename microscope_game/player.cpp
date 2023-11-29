#include "player.h"
player::player(const char* texturesheet, int x, int y, int w, int h,int velocity,int a,int b,int p) :GameObject(texturesheet, x, y, w, h) {
    vel = velocity;
    attack = a;
    blood = b;
    alive = true;
    price = p;
    moving = true;
}
player::~player() {
    cout << "player deconstructor()" << endl;
}
void player::update() {
    if (moving) {
        xpos -= vel;
        destR.x = xpos;
        if (xpos <= 150) {
            xpos = 150;
            moving = false;
        }
    }
}
void player::render() {
    GameObject::render();
}

