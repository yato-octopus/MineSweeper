#pragma once
#include <Siv3D.hpp>

class Game {
public:
	enum State {
		START,
		GAME,
		CLEAR,
		END,
	};
	Game();
	void start();
	void update();
	void draw();
	void open(int, int);
	void check(int,int);
	void map_draw();
	void game_end();
	void game_count();
	void deploy_bomb();

private:
	State state;
	int rect_y;
	int rect_x;
	int sum[4] = { 0 };
	int col[10][10] = { 0 };
	int bomb_count[10][10] = { 0 };
};

