#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player()
{
	//Prêdkoœæ gracza
	pSpeed = 150;

	//Za³adowanie tekstury gracza
	if (!(pTexture.loadFromFile("data/player.png")))
	{
		cout << "nie zaladowano tekstury gracza";
	}
	pSprite.setTexture(pTexture);

	//Przestawienie punktu zaczepienia
	pSprite.setOrigin(20, 20);

	//Ustawienie pozycji gracza
	pPosition.x = 100;
	pPosition.y = 100;
}

//Tworzy dostêp do prywatnego sprite dla funkcji draw()
Sprite Player::getSprite()
{
	return pSprite;
}
//Ruch i obrót gracza
void Player::moveLeft()
{
	pLeftPressed = true;
	pUpPressed = false;
	pDownPressed = false;
	collision = pColission();
	pSprite.setRotation(-90);
}
void Player::moveRight()
{
	pRightPressed = true;
	pUpPressed = false;
	pDownPressed = false;
	collision = pColission();
	pSprite.setRotation(90);
}
void Player::moveUp() 
{
	pUpPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
	collision = pColission();
	pSprite.setRotation(0);
}
void Player::moveDown()
{
	pDownPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
	collision = pColission();
	pSprite.setRotation(180);
}

void Player::stopLeft()
{
	pLeftPressed = false;
}
void Player::stopRight()
{
	pRightPressed = false;
}
void Player::stopUp()
{
	pUpPressed = false;
}
void Player::stopDown()
{
	pDownPressed = false;
}

//Ruch gracza na wejsciu klatki
void Player::update(float elapsedTime)
{
	if (pRightPressed && collision)
	{
		pPosition.x += pSpeed * elapsedTime;

	}
	if (pLeftPressed && collision)
	{
		pPosition.x -= pSpeed * elapsedTime;
	}
	if (pUpPressed && collision)
	{
		pPosition.y -= pSpeed * elapsedTime;
	}
	if (pDownPressed && collision)
	{
		pPosition.y += pSpeed * elapsedTime;
	}
	//Przeniesienie ruchu sprite do nowej pozycji
	pSprite.setPosition(pPosition);
}
Player::~Player()
{
}
