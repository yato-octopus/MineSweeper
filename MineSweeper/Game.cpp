#include "Game.h"
#include <Siv3D.hpp>

Game::Game() {
	start();
}
void Game::start() {
	state = State::GAME;
	Window::Resize(408, 480);
}
void Game::update() {
	switch (state) {
	case State::START:
		if (Input::KeySpace.clicked) {
			state = State::GAME;
		}
		break;
	case State::GAME:
		if (Input::KeySpace.clicked) {
			state = State::CLEAR;
		}
		break;
	case State::CLEAR:
		if (Input::KeySpace.clicked) {
			state = State::START;
		}
		break;
	}
}
void Game::draw() {
	static Font fontS(30);

	switch (state) {
	case State::START:
		fontS(L"マインスイーパー").drawCenter(100 - fontS.ascent);
		fontS(L"すたーと").drawCenter(300,Palette::Yellow);
		break;
	case State::GAME:
		map_draw();
		break;
	case State::CLEAR:
		break;
	}
}
void Game::check() {

}
void Game::map_draw() {
	static Font fontS(30);
	Line_x = 4;
	Line_y = 76;
	rect_x = 0;
	rect_y = 0;
	//ゲーム画面上部
	Rect(0, 0, 408, 72).draw(Palette::Black);
	fontS(L"Reset").draw(250, 0, Palette::Skyblue);
	//ゲーム画面
	for (int n = 1; n <= 8;n++) {
		for (int j = 1; j <= 8; j++) {
			Rect(8 + rect_x, 80 + rect_y, 42, 42).draw(Palette::Blue);
			rect_x += 50;
		}
		rect_x = 0;
		rect_y += 50;
	}
	for (int i = 1; i <= 9; i++) {
		Line(0, Line_y, 520, Line_y).draw(8, Palette::Skyblue);
		Line_y += 50;
		Line(Line_x, 80, Line_x, 480).draw(8, Palette::Skyblue);
		Line_x += 50;
	}

}
