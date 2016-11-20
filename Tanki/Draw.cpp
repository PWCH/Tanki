#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czyœci ostatni¹ klatkê
	gameWindow.clear(Color::White);
	
	//Rysuje t³o
	gameWindow.draw(gameBackgroudSprite);

	//Rysuje gracza
	gameWindow.draw(pPlayer.getSprite());

	//Rysuje przeciwników
	//gameWindow.draw(enemy[5].generateEnemy());
	gameWindow.display();

}