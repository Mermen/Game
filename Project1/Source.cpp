#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <sstream>
#include "map.h"
#include "view.h"
#include "interactionWithUnit.h"

using namespace std;
using namespace sf;
class Player {
private: float x, y;
	public:
		float w, h, dx, dy, speed;
		int dir, playerScore;
		String File;
		Image image;
		Texture texture;
		Sprite sprite;
		Player(String F, float X, float Y, float W, float H) {
			dx = 0; dy = 0; speed = 0; dir = 0, playerScore = 0;
			File = F;
			w = W; h = H;
			image.loadFromFile("images/" + File);
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			x = X; y = Y;
			sprite.setTextureRect(IntRect(0, 0, w, h));
		}
		void update(float time) {
			for (int i = x; i < x + w; i++) {
				for (int j = y; j < y + h; j++) {
					MapUnit[i][j] = 0;
				}

			}
			switch (dir) {
				case 0:
					dx = speed; dy = 0; break;
				case 2:
					dx = -speed; dy = 0; break;
				case 3:
					dx = 0; dy = speed; break;
				case 1:
					dx = 0; dy = -speed; break;
			}
			x += dx * time;
			y += dy * time;

			interactionWithMap();
			//interactionWithUnit(dir);
			setUnit(x, y, w, h);
			speed = 0;

			sprite.setPosition(x, y);
		}
		void interactionWithMap() {
			for (int i=y/32; i<(y+h)/32 ; i++)
				for (int j = x/32; j < (x+w)/32; j++){
				
					if (TileMap[i][j]=='0'){
						if (dy>0){
							y = i * 32 - h;
						}
						if (dy<0){
							y = i * 32 + 32;
						}
						if (dx>0){
							x = j * 32 - w;
						}
						if (dx<0){
							x = j * 32 + 32;
						}
					}
					if (TileMap[i][j]=='s') {
						playerScore++;
						TileMap[i][j] = ' ';
					}
					
				}
		}
		/*void interactionWithUnit(int dir) {
			switch (dir)
			{
				case 0: {

					for (int i = y; i < y+h; i++)
					{
						if (MapUnit[x + h][i] == 1) {

						}
					}
					break;
				}
				case 1: {

					break;
				}
				case 2: {

					break;
				}
				case 3: {

					break;
				}
			}
		}*/
		float getplayercoordinateX() {
			return x;
		}
		float getplayercoordinateY() {
			return y;
		}

};

int main() {
	Font font;
	font.loadFromFile("times-new-roman.ttf");
	Text text("", font, 20);
	text.setColor(Color::Cyan);
	int v=1;
	RenderWindow window(VideoMode(1344,378), "Lion_Tank");
	view.reset(FloatRect(0, 0, 672, 378));
	view1.reset(FloatRect(0, 0, 672, 378));
	view.setViewport(FloatRect(0, 0, 0.5f, 1));
	view1.setViewport(FloatRect(0.5f, 0, 0.5f, 1));
	Clock clock; 
	float CurrentFrame = 0;
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	Player p("hero.png", 33,33, 96.0, 96.0);
	Player t("tank.png", 1181, 701, 66.0, 66.0);
	getplayer0coordinateforview(t.getplayercoordinateX(), t.getplayercoordinateY());
	getplayer1coordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
	GenerateUnit();
	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		if (true)
		{
			if ((Keyboard::isKeyPressed(Keyboard::A))) {
				t.dir = 2; t.speed = 0.15;
				t.sprite.setTextureRect(IntRect(132, 0 , 66, 66));
				v = 1;
				getplayer0coordinateforview(t.getplayercoordinateX(), t.getplayercoordinateY());
			}
			if ((Keyboard::isKeyPressed(Keyboard::D))) {
				t.dir = 0; t.speed = 0.15;
				t.sprite.setTextureRect(IntRect(0, 0, 66, 66));
				v = 1;
				getplayer0coordinateforview(t.getplayercoordinateX(), t.getplayercoordinateY());
			}
			if ((Keyboard::isKeyPressed(Keyboard::W))) {
				t.speed = 0.15;
				t.dir = 1;
				t.sprite.setTextureRect(IntRect(66, 0, 66, 66));
				v = 1;
				getplayer0coordinateforview(t.getplayercoordinateX(), t.getplayercoordinateY());
			}
			if ((Keyboard::isKeyPressed(Keyboard::S))) {
				t.dir = 3; t.speed = 0.15;
				t.sprite.setTextureRect(IntRect(198, 0, 66, 66));
				v = 1;
				getplayer0coordinateforview(t.getplayercoordinateX(), t.getplayercoordinateY());
			}
		}
		if (true)
		{
			if ((Keyboard::isKeyPressed(Keyboard::Left))) {
				p.dir = 2; p.speed = 0.15;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3)
					CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
				v = 2;
				getplayer1coordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right))) {
				p.dir = 0; p.speed = 0.15;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3)
					CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
				v = 2;
				getplayer1coordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up))) {
				p.dir = 1; p.speed = 0.15;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3)
					CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));
				v = 2;
				getplayer1coordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down))) {
				p.dir = 3; p.speed = 0.15;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3)
					CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
				v = 2;
				getplayer1coordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
		}
		p.update(time);
		t.update(time);
		viewmap(time);
		
		window.clear();
		changeview();
		
		
		window.setView(view);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++) {
				if (TileMap[i][j] == ' ')
					s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')
					s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if (TileMap[i][j] == '0')
					s_map.setTextureRect(IntRect(64, 0, 32, 32));
				s_map.setPosition(32 * j, 32 * i);
				window.draw(s_map);
			}
		ostringstream player0ScoreString;
		player0ScoreString<<t.playerScore;
		text.setString("Collected Stones: "+ player0ScoreString.str());
		text.setPosition(view.getCenter().x - view.getSize().x*7.0 / 16.0, view.getCenter().y - view.getSize().y * 7.0 / 16.0);
		window.draw(p.sprite);
		window.draw(t.sprite);
		window.draw(text);
		window.setView(view1);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++) {
				if (TileMap[i][j] == ' ')
					s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')
					s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if (TileMap[i][j] == '0')
					s_map.setTextureRect(IntRect(64, 0, 32, 32));
				s_map.setPosition(32 * j, 32 * i);
				window.draw(s_map);
			}
		ostringstream player1ScoreString;
		player1ScoreString << p.playerScore;
		text.setString("Collected Stones: " + player1ScoreString.str());
		text.setPosition(view1.getCenter().x-view1.getSize().x*7.0/16.0, view1.getCenter().y - view1.getSize().y * 7.0 / 16.0);
		window.draw(t.sprite);
		window.draw(p.sprite);
		window.draw(text);
		window.display();
	}
	return 0;
}