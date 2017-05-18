#pragma once
#include <Siv3D.hpp>

class Game {
public:
	enum State {
		START,
		GAME,
		CLEAR,
	};
	Game();
	void start();
	void update();
	void draw();
	void input();
	void check();
	void map_draw();

private:
	State state;
	int Line_y;
	int Line_x;
	int rect_y;
	int rect_x;
};

