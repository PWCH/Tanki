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
	pLeftCollision = false;
	pRightCollision = false;
	pSprite.setRotation(0);
}
void Player::moveDown()
{
	pDownPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
	pLeftCollision = false;
	pRightCollision = false;
	pSprite.setRotation(180);
}

void Player::stopLeft()
{
	pLeftPressed = false;
	pLeftCollision = false;
}
void Player::stopRight()
{
	pRightPressed = false;
	pRightCollision = false;
}
void Player::stopUp()
{
	pUpPressed = false;
	pTopCollision = false;
}
void Player::stopDown()
{
	pDownPressed = false;
	pDownCollision = false;
}

//Ruch gracza na wejsciu klatki
void Player::update(float elapsedTime)
{
	pColission();
	if (pRightPressed && !(pRightCollision))
	{	
		pPosition.x += pSpeed * elapsedTime;
	}
	if (pUpPressed && !(pTopCollision))
	{
		pPosition.y -= pSpeed * elapsedTime;
	}
	if (pLeftPressed && !(pLeftCollision))
	{
		pPosition.x -= pSpeed * elapsedTime;
	}
	else if (pDownPressed && !(pDownCollision))
	{
		pPosition.y += pSpeed * elapsedTime;
	}
	//Przeniesienie ruchu sprite do nowej pozycji
	pSprite.setPosition(pPosition);
}
Player::~Player()
{
}
