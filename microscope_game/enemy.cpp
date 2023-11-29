#include "enemy.h"
enemy::enemy(const char* texturesheet, int x, int y, int w, int h,double ww,double hh, int velocity, int a, int b) :GameObject(texturesheet, x, y, w, h,ww,hh) {
    vel = velocity;
    attack = a;
    blood = b;
    alive = true;
    moving = true;
}
enemy::~enemy() {
    cout << "player deconstructor()" << endl;
}
void enemy::update() {
    if (moving) {
        xpos += vel;
        destR.x = xpos;
        if (xpos >= 570) {
            xpos = 570;
            moving = false;
        }
    }
}
void enemy::render() {
    GameObject::render();
}

