#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czyœci ostatni¹ klatkê
	gameWindow.clear(Color::White);

	//Rysuje tlo
	gameWindow.draw(gameBackgroudSprite);

	//Rysuje gracza
	gameWindow.draw(pPlayer.getSprite());

	//Rysuje przeciwnika
	gameWindow.draw(enemy.generateEnemy());

	//Rysuje pociski tylko problem z kasowaniem :(
	for (int i = playerBullets.size() - 1; i > 0; --i)
	{
		gameWindow.draw(playerBullets[i].getSprite());
		/*Sprawdzenie czy ma kasowaæ i usuwanie, ale nie dzia³a. Kolizja jest wykrywania ale lepiej to by wygl¹da³o gdy
		1) Dodawanie pocisków powinno byæ przez funkcjê bullet.addBullet()
		2) Usuwanie pocisków powinno byæ po sprawdzeniu bullet.removeBullet() i po³¹czone z bullet.Update()
		Proponowane rozwi¹zanie:
		Stworzyæ globalny vector <Bullet> i na nim dzia³aæ w klasie Bullet
		*/
		//if (playerBullets[i].removeBullet())
		//{
		//	playerBullets[0] = playerBullets[i];
		//	playerBullets[i] = playerBullets[playerBullets.size() - 1];
		//	playerBullets[playerBullets.size() - 1] = playerBullets[0];
		//	playerBullets.pop_back();
		//}
		//else {}

	}
	//Rysuje przeciwników
	//gameWindow.draw(enemy[5].generateEnemy());
	gameWindow.display();

}
