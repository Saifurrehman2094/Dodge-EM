#include <SFML/Graphics.hpp>
using namespace sf;

class reward {
public:
	Texture te;
	Sprite s;
	float x_axis, y_axis;
public:
	reward():x_axis(0),y_axis(0){}
	reward(String image, float x, float y):x_axis(x),y_axis(y) {

	}
	virtual int addScore(int& score) = 0;


};
class Rectangle : public reward {

public:
	Rectangle(String image, float x, float y) :reward(image, x, y) {
		te.loadFromFile(image);
		s.setTexture(te);
		s.setPosition(x, y);
		s.setScale(0.08, 0.08);
		x_axis = x;
		y_axis = y;
	}


	int addScore(int& score)override {
		score = score + 5;
		return score;
	}


};
class Circle : public reward {

public:
	Circle(String image, float x, float y) :reward(image, x, y) {
		te.loadFromFile(image);
		s.setTexture(te);
		s.setPosition(x, y);
		s.setScale(0.05, 0.05);
		x_axis = x;
		y_axis = y;
	}

	int addScore(int& score)override {
		score = score + 10;
		return score;
	}


};
class Triangle :public reward {

public:
	Triangle(String image, float x, float y) :reward(image, x, y) {
		te.loadFromFile(image);
		s.setTexture(te);
		s.setPosition(x, y);
		s.setScale(0.15, 0.15);
		x_axis = x;
		y_axis = y;
	}

	int addScore(int& score)override {
		score = score + 10;
		return score;
	}


};
class Hexagon :public reward {

public:
	Hexagon(String image, float x, float y) :reward(image, x, y) {
		te.loadFromFile(image);
		s.setTexture(te);
		s.setPosition(x, y);
		s.setScale(0.12, 0.12);
		x_axis = x;
		y_axis = y;
	}

	int addScore(int& score)override {
		score = score + 10;
		return score;
	}


};