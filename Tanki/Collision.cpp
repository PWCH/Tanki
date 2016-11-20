#include "SFML\Graphics.hpp"
#include <iostream>
#include "Player.h"


using namespace std;
using namespace sf;

bool Player::pColission()
{
	//Ograniczenie obszaru sceny poprzez utworzenie linii
	int lineSize = 670;

	//Lewa krawêdŸ
	RectangleShape leftCollision(Vector2f(1, lineSize));
	leftCollision.setPosition(50, 50);
	FloatRect positionLCollision = leftCollision.getGlobalBounds();

	//Prawa krawêdŸ
	RectangleShape rightCollision(Vector2f(1, lineSize));
	rightCollision.setPosition(700, 50);
	FloatRect positionPCollision = rightCollision.getGlobalBounds();
	
	//Górn krawêdŸ
	RectangleShape topCollision(Vector2f(lineSize, 1));
	topCollision.setPosition(700, 50);
	FloatRect positionTCollision = topCollision.getGlobalBounds();

	//Dolna krawêdŸ
	RectangleShape downCollision(Vector2f(lineSize, 1));
	downCollision.setPosition(50, 50);
	FloatRect positionDCollision = downCollision.getGlobalBounds();

	FloatRect playerPosition = pSprite.getGlobalBounds();
	if (positionPCollision.intersects(playerPosition))
	{
		cout << "Prawa kolizja";
		return true;
	}
	if (positionLCollision.intersects(playerPosition))
	{
		cout << "Lewa kolizja";
		return true;
	}
	if (positionTCollision.intersects(playerPosition))
	{
		cout << "Górna kolizja";
		return true;
	}
	if (positionDCollision.intersects(playerPosition))
	{
		cout << "Dolna kolizja";
		return true;
	}

	//if (playerPosition.contains(rightCollision))
	//{
	//	cout << "Prawa kolizja";
	//}
	//if (playerPosition.contains(topCollision))
	//{
	//	cout << "Gorna kolizja";
	//}
	//if (playerPosition.contains(downCollision))
	//{
	//	cout << "Dolna kolizja";
	//}
}