#include "Bullet.h"
#include <iostream>

using namespace std;


Bullet::Bullet(bool can)
{
	killPlayer = can;

	//Wczytanie tekstury pocisku
	if (!(bulletTexture.loadFromFile("data/bullet.png")))
	{
		cout << "Nie zaladowano tekstury pocisku";
	}
	bulletSprite.setTexture(bulletTexture);

	//Ustawienie punktu zaczepienia pocisku
	bulletSprite.setOrigin(10, 10);
}


Bullet::~Bullet()
{
}
