#include "Bullet.h"


Bullet::Bullet(int kierunek, Vector2f pozycjaGracza/* kierunek/*,Texture *bulletTexture*/)
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
       // pRightPressed = false;
        //pLeftPressed = false;
        bulletSprite.setRotation(0);
    }
    if(kierunek == 2)
    {
        pDownPressed = true;
       // pRightPressed = false;
      //  pLeftPressed = false;
        bulletSprite.setRotation(180);
    }
    if(kierunek == 3)
    {
        pLeftPressed = true;
      //  pUpPressed = false;
      //  pDownPressed = false;
        bulletSprite.setRotation(-90);
    }
    if(kierunek == 4)
    {
        pRightPressed = true;
     //   pUpPressed = false;
     //   pDownPressed = false;
        bulletSprite.setRotation(90);
    }
	//pDownCollision = true;
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

bool Bullet::bulletColission()
{
	//Ograniczenie obszaru sceny poprzez utworzenie linii
	int lineSize = 650;

	//Ustawienie rogów obszaru sceny
	Vector2f lefttopcorner(40, 80);
	Vector2f leftdowncorner(40, 580);
	Vector2f righttopcorner(700, 40);

	//Lewa krawêdŸ
	RectangleShape leftCollision(Vector2f(1, lineSize));
	leftCollision.setPosition(Vector2f(lefttopcorner));
	FloatRect positionLCollision = leftCollision.getGlobalBounds();

	//Prawa krawêdŸ
	RectangleShape rightCollision(Vector2f(1, lineSize));
	rightCollision.setPosition(Vector2f(righttopcorner));
	FloatRect positionPCollision = rightCollision.getGlobalBounds();

	//Górna krawêdŸ
	RectangleShape topCollision(Vector2f(lineSize, 1));
	topCollision.setPosition(Vector2f(lefttopcorner));
	FloatRect positionTCollision = topCollision.getGlobalBounds();

	//Dolna krawêdŸ
	RectangleShape downCollision(Vector2f(lineSize, 1));
	downCollision.setPosition(Vector2f(leftdowncorner));
	FloatRect positionDCollision = downCollision.getGlobalBounds();

	FloatRect bulletPosition = bulletSprite.getGlobalBounds();

	//Warunki kolizji ze brzegami sceny
	if (positionPCollision.intersects(bulletPosition))
	{
		//cout << "Prawa kolizja";
		pRightCollision = true;
	}
	if (positionLCollision.intersects(bulletPosition))
	{
		//cout << "Lewa kolizja";
		pLeftCollision = true;
	}
	if (positionTCollision.intersects(bulletPosition))
	{
		//cout << "Gorna kolizja";
		pTopCollision = true;
	}
	if (positionDCollision.intersects(bulletPosition))
	{
		//cout << "Dolna kolizja";
		pDownCollision = true;
	}
	if ((pDownCollision && pRightCollision) || (pDownCollision && pLeftCollision))
	{
		return pDownCollision;
	}
	else if ((pTopCollision && pRightCollision) || (pTopCollision && pLeftCollision))
	{
		return pTopCollision;
	}
	else if (pRightCollision)
	{
		return pRightCollision;
	}
	else if (pLeftCollision)
	{
		return pLeftCollision;
	}
	else if (pTopCollision)
	{
		return pTopCollision;
	}
	else if (pDownCollision)
	{
		return pDownCollision;
	}
}

void Bullet::update(float elapsedTime)
{
    //pColission();
    if(pUpPressed == true /*&& !(pTopCollision)*/)bulletPosition.y -= bulletSpeed * elapsedTime;
    if(pDownPressed == true/* && !(pDownCollision)*/)bulletPosition.y += bulletSpeed * elapsedTime;
    if(pLeftPressed == true /*&& !(pLeftCollision)*/)bulletPosition.x -= bulletSpeed * elapsedTime;
    if(pRightPressed == true/* && !(pRightCollision)*/)bulletPosition.x += bulletSpeed * elapsedTime;
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

