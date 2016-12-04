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

	//Rysuje pociski tylko problem z kasowaniem :(
	for (int i = playerBullets.size() - 1; i > 0; --i)
	{
		gameWindow.draw(playerBullets[i].getSprite());
		/*Sprawdzenie czy ma kasowa� i usuwanie, ale nie dzia�a. Kolizja jest wykrywania ale lepiej to by wygl�da�o gdy
		1) Dodawanie pocisk�w powinno by� przez funkcj� bullet.addBullet()
		2) Usuwanie pocisk�w powinno by� po sprawdzeniu bullet.removeBullet() i po��czone z bullet.Update()
		Proponowane rozwi�zanie:
		Stworzy� globalny vector <Bullet> i na nim dzia�a� w klasie Bullet
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
	//Rysuje przeciwnik�w
	//gameWindow.draw(enemy[5].generateEnemy());
	gameWindow.display();

}
