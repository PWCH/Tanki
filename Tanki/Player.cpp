#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player()
{
	//Prêdkoœæ gracza
	pSpeed = 400;

	//Za³adowanie tekstury gracza
	if (!(pTexture.loadFromFile("data/gracz.png")))
	{
		cout << "nie zaladowano tekstury gracza";
	}
	pSprite.setTexture(pTexture);

	//Ustawienie pozycji gracza
	pPosition.x = 100;
	pPosition.y = 100;
}

//Tworzy dostêp do prywatnego sprite dla funkcji draw()
Sprite Player::getSprite()
{
	return pSprite;
}

void Player::moveLeft()
{
	pLeftPressed = true;
}
void Player::moveRight()
{
	pRightPressed = true;
}
void Player::moveUp() 
{
	pUpPressed = true;
}
void Player::moveDown()
{
	pDownPressed = true;
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
