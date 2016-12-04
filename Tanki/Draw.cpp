#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czy�ci ostatni� klatk�
	gameWindow.clear(Color::White);

	//Rysuje tlo
	gameWindow.draw(gameBackgroudSprite);

	//Rysuje gracza
	gameWindow.draw(pPlayer.getSprite());

	for(int i = playerBullets.size()-1; i > 0; --i)
        gameWindow.draw(playerBullets[i].getSprite());

	//Rysuje przeciwnik�w
	//gameWindow.draw(enemy[5].generateEnemy());
	gameWindow.display();

}
