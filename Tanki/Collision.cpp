#include "SFML\Graphics.hpp"
#include <iostream>
#include "Player.h"


using namespace std;
using namespace sf;

bool Player::pColission()
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
	
	//Górn krawêdŸ
	RectangleShape topCollision(Vector2f(lineSize, 1));
	topCollision.setPosition(Vector2f(lefttopcorner));
	FloatRect positionTCollision = topCollision.getGlobalBounds();

	//Dolna krawêdŸ
	RectangleShape downCollision(Vector2f(lineSize, 1));
	downCollision.setPosition(Vector2f(leftdowncorner));
	FloatRect positionDCollision = downCollision.getGlobalBounds();

	FloatRect playerPosition = pSprite.getGlobalBounds();
	if (positionPCollision.intersects(playerPosition))
	{
		//cout << "Prawa kolizja";
		pRightCollision = true;
	}
	if (positionLCollision.intersects(playerPosition))
	{
		//cout << "Lewa kolizja";
		pLeftCollision = true;
	}
	if (positionTCollision.intersects(playerPosition))
	{
		//cout << "Gorna kolizja";
		pTopCollision = true;
	}
	if (positionDCollision.intersects(playerPosition))
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