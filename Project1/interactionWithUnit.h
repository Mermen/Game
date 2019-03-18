#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <sstream>

const int WIDTH_MAP = 1280;
const int HEIGHT_MAP = 800;

int MapUnit[WIDTH_MAP][HEIGHT_MAP];
void GenerateUnit() {
	for (int i = 0; i < WIDTH_MAP; i++) {
		for (int j = 0; j < HEIGHT_MAP; j++) {
			MapUnit[i][j] = 0;
		}
	}
}
void setUnit(float x, float y, float w, float h) {
	for (int i = x; i < x+w; i++) {
		for (int j = y; j < y+h; j++) {
			MapUnit[i][j] = 1;
		}

	}
}
