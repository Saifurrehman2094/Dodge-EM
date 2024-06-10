#ifndef Car_h
#define Car_h
#include "libararies.h"
using namespace sf;
class Car {
	int x;
	int y;
public:
	Car() :x(0), y(0) {};
	virtual void setx(int a) {
		x = a;
	}
	void sety(int a) {
		y = a;
	}
	int getx()const {
		return x;
	}
	int gety()const {
		return y;
	}

};
class Enemy : public Car{
	Texture tex;
	Sprite sprite;
public:
	Enemy() {
		tex.loadFromFile("img/Car2.png");
		sprite.setTexture(tex);
		sprite.setPosition(420,790 );
		sprite.rotate(-90);
		sprite.scale(0.2, 0.2);
		sprite.setOrigin(sprite.getLocalBounds().width, 0);
	}
	Sprite& getsprite() {
		return sprite;
	}

	void setx(int a) override {

	}
};
class Player : public Car {
	Texture tex;
	Sprite sprite;
	int lives;
public:
	Player() {
		lives = 3;
		tex.loadFromFile("img/Car.png");
		sprite.setTexture(tex);
		sprite.setPosition(750, 790);
		sprite.rotate(90);
		sprite.scale(0.2, 0.2);
		//sprite.
	}
	Sprite& getsprite() {
		return sprite;
	}
	int getlive() {
		return lives;
	}
	void setl(int a) {
		lives = a;
	}


};
#endif // !Car_h
