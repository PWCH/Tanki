#include "Bullet.h"


Bullet::Bullet(int kierunek, Vector2f pozycjaGracza/* kierunek, Texture *bulletTexture*/)
{
	killPlayer = true;

	//this -> bulletTexture = *bulletTexture;
	//predkosc pocisku
	bulletSpeed = 150;

	//Wczytanie tekstury pocisku
	if (!(bulletTexture.loadFromFile("data/bullet.png")))
	{
		cout << "Nie zaladowano tekstury pocisku";
	}
	bulletSprite.setTexture(bulletTexture);

	//Ustawienie punktu zaczepienia pocisku
	Vector2u bulletSize = bulletTexture.getSize();
	bulletSprite.setOrigin(bulletSize.x / 2, bulletSize.y / 2);

    //ustawianie pozycji pocisku
	bulletPosition.x = pozycjaGracza.x;
	bulletPosition.y = pozycjaGracza.y;

	bulletSprite.setPosition(bulletPosition);

    if(kierunek == 1)
    {
        pUpPressed = true;
        bulletSprite.setRotation(0);
    }
    if(kierunek == 2)
    {
        pDownPressed = true;
        bulletSprite.setRotation(180);
    }
    if(kierunek == 3)
    {
        pLeftPressed = true;
        bulletSprite.setRotation(-90);
    }
    if(kierunek == 4)
    {
        pRightPressed = true;
        bulletSprite.setRotation(90);
    }
}

void Bullet::moveBullets()
{
    //bulletColission();
	//if (pRightPressed && !(pRightCollision))
	{
	//	bulletPosition.x += bulletSpeed * elapsedTime;
	}
	//else if (pDownPressed && !(pDownCollision))
	{
		//bulletPosition.y += bulletSpeed * elapsedTimebulletSprite;
		//bulletSprite.y += bulletSpeed * elapsedTime;
	}
}

bool Bullet::removeBullet()
{
	if (pTopCollision == 1 || pDownCollision == 1 || pLeftCollision == 1 || pRightCollision == 1)
		return false;

	else return true;
}

void Bullet::update(float elapsedTime)
{
	bulletColission();
    if(pUpPressed == true && !(pTopCollision))
		bulletPosition.y -= bulletSpeed * elapsedTime;
    if(pDownPressed == true && !(pDownCollision))
		bulletPosition.y += bulletSpeed * elapsedTime;
    if(pLeftPressed == true && !(pLeftCollision))
		bulletPosition.x -= bulletSpeed * elapsedTime;
    if(pRightPressed == true && !(pRightCollision))
		bulletPosition.x += bulletSpeed * elapsedTime;
    bulletSprite.setPosition(bulletPosition);
}

void Bullet::addBullet()
{
	//allBullets.push_back(new Bullet());
}

Sprite Bullet::getSprite()
{
	return bulletSprite;
}

Bullet::~Bullet()
{
}

