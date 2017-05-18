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
	static Font fontS(40);
	static Font fontL(10);

	switch (state) {
	case State::START:
		fontS(L"�}�C���X�C�[�p�[").drawCenter(100 - fontS.ascent);
		fontS(L"�����[��").drawCenter(300,Palette::Yellow);
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
	Line_x = 4;
	Line_y = 76;
	rect_x = 0;
	rect_y = 0;

	//�Q�[�����
	for (int j = 1; j <= 8;j++) {
		Rect(8 + rect_x, 80, 42, 42).draw(Palette::Blue);
		rect_x += 48;
		for (int k = 1; k <= 8; k++) {
			Rect(8, 80 + rect_y, 42, 42).draw(Palette::Blue);
			rect_y += 48;
		}
	}
	for (int i = 1; i <= 9; i++) {
		Line(0, Line_y, 520, Line_y).draw(8, Palette::Skyblue);
		Line_y += 50;
		Line(Line_x, 80, Line_x, 480).draw(8, Palette::Skyblue);
		Line_x += 50;
	}

}
