#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czy�ci ostatni� klatk�
	gameWindow.clear(Color::White);
	
	//Rysuje t�o
	gameWindow.draw(gameBackgroudSprite);

	//Rysuje gracza
	gameWindow.draw(pPlayer.getSprite());

	//Rysuje przeciwnik�w
	//gameWindow.draw(enemy[5].generateEnemy());
	gameWindow.display();

}