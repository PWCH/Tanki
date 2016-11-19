#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player()
{
	//Pr�dko�� gracza
	pSpeed = 400;

	//Za�adowanie tekstury gracza
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

//Tworzy dost�p do prywatnego sprite dla funkcji draw()
Sprite Player::getSprite()
{
	return pSprite;
}
//Ruch i obr�t gracza
void Player::moveLeft()
{
	pLeftPressed = true;
	pUpPressed = false;
	pDownPressed = false;
	pSprite.setRotation(-90);
}
void Player::moveRight()
{
	pRightPressed = true;
	pUpPressed = false;
	pDownPressed = false;
	pSprite.setRotation(90);
}
void Player::moveUp() 
{
	pUpPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
	pSprite.setRotation(0);
}
void Player::moveDown()
{
	pDownPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
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
	if (pRightPressed)
	{
		pPosition.x += pSpeed * elapsedTime;
	}
	if (pLeftPressed)
	{
		pPosition.x -= pSpeed * elapsedTime;
	}
	if (pUpPressed)
	{
		pPosition.y -= pSpeed * elapsedTime;
	}
	if (pDownPressed)
	{
		pPosition.y += pSpeed * elapsedTime;
	}
	//Przeniesienie ruchu sprite do nowej pozycji
	pSprite.setPosition(pPosition);
}
Player::~Player()
{
}
