#include "Bullet.h"


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
	Vector2u bulletSize = bulletTexture.getSize();
	bulletSprite.setOrigin(bulletSize.x / 2, bulletSize.y / 2);
}

void Bullet::addBullet()
{
	allBullets.push_back(new Bullet());
}


Bullet::~Bullet()
{
}
