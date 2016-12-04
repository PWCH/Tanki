#include "Engine.h"

void Engine::input()
{
	if (Event::Closed)
	{
		gameWindow.close();
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		gameWindow.close();
	}
	// Czytanie ruchu gracza
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		pPlayer.moveUp();
		kierunek = 1;
	}
	else
	{
		pPlayer.stopUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		pPlayer.moveDown();
		kierunek = 2;
	}
	else
	{
		pPlayer.stopDown();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		pPlayer.moveLeft();
		kierunek = 3;
	}
	else
	{
		pPlayer.stopLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		pPlayer.moveRight();
		kierunek = 4;
	}
	else
	{
		pPlayer.stopRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && tylkoRaz>=150)
	{
		cout << "Dodano pocisk";

		Bullet bullet(kierunek, pPlayer.pPosition);/*bullet.kierunek = Bullet::UP/*true/*, &bulletTexture*/
		playerBullets.push_back(bullet);

		tylkoRaz = 0;


		//okreslanie kierunku pocisku
//		if(pPlaye.pLeftPressed == true) playerBullets::kierunek = Kierunek = UP;
	}
}
