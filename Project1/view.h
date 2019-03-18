#include <SFML/Graphics.hpp>
using namespace sf;

View view, view1;
void viewmap(float time){}
void changeview(){}
void getplayer0coordinateforview(float x, float y) {
	float tempx, tempy, sizeplayer;
	sizeplayer = 33.0;
	tempx = x + sizeplayer;
	tempy = y + sizeplayer;
	if (tempx<(view.getSize().x)/2) {
		tempx = (view.getSize().x)/2;
	}
	if (tempx > 1280.0- (view.getSize().x) / 2) {
		tempx = 1280.0 - view.getSize().x/2;
	}
	if (tempy < view.getSize().y / 2) {
		tempy = view.getSize().y/2;
	}
	if (tempy > 800.0 - view.getSize().y / 2) {
		tempy = 800.0 - view.getSize().y/2;
	}
	view.setCenter(tempx, tempy);
}
void getplayer1coordinateforview(float x, float y) {
	float tempx, tempy, sizeplayer;
	sizeplayer = 48.0;
	tempx = x + sizeplayer;
	tempy = y + sizeplayer;
	if (tempx < (view.getSize().x) / 2) {
		tempx = (view.getSize().x) / 2;
	}
	if (tempx > 1280.0 - (view.getSize().x) / 2) {
		tempx = 1280.0 - view.getSize().x / 2;
	}
	if (tempy < view.getSize().y / 2) {
		tempy = view.getSize().y / 2;
	}
	if (tempy > 800.0 - view.getSize().y / 2) {
		tempy = 800.0 - view.getSize().y / 2;
	}
	view1.setCenter(tempx, tempy);
}
/*void viewmap(float time) {
	if (Keyboard::isKeyPressed(Keyboard::Numpad6)) {
		view1.move(0.15*time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Numpad8)) {
		view1.move(0, -0.15*time);
	}
	if (Keyboard::isKeyPressed(Keyboard::Numpad4)) {
		view1.move(-0.15*time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Numpad2)) {
		view1.move(0, 0.15*time);
	}
}
void changeview() {
	if (Keyboard::isKeyPressed(Keyboard::U))
	{
		view.zoom(1.0100f);
	}
	if (Keyboard::isKeyPressed(Keyboard::J))
	{
		view.zoom(0.9900f);
	}
	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		view.rotate(90);
	}
	if (Keyboard::isKeyPressed(Keyboard::I))
	{
		view.setSize(640,360);
	}
}*/