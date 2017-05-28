
#include <Siv3D.hpp>
#include "Game.h"

void Main(){
	Window::Resize(408, 480);
	Game game;

	while (System::Update()) {
		game.draw();
		game.update();
	}
}
