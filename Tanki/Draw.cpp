#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czy�ci ostatni� klatk�
	gameWindow.clear(Color::White);
	
	//Rysuje t�o
	gameWindow.draw(gameBackgroudSprite);
	gameWindow.draw(pPlayer.getSprite());

	gameWindow.display();

}