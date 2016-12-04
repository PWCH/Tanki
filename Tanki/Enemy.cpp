#include "Enemy.h"

Enemy::Enemy()
{
    cout << "\n\nNie zaladowano tekstury przeciwnika";
	//Liczba przeciwników
	//noEnemies = 5;
	enemySpeed = 50;

	//Wczytanie tekstury przeciwnika
	if (!(enemyTexture.loadFromFile("data/enemy.png")))
	{
		cout << "Nie zaladowano tekstury przeciwnika";
	}
	enemySprite.setTexture(enemyTexture);

	//Ustawienie punktu zaczepienia przecinika
	Vector2u enemySize = enemyTexture.getSize();
	enemySprite.setOrigin(enemySize.x / 2, enemySize.y / 2);

	enemyPosition.x = 100;
	enemyPosition.y = 100;
	enemySprite.setPosition(enemyPosition);
}

Sprite Enemy::generateEnemy()
{
	return enemySprite;
}

void Enemy::update(float elapsedTime, Vector2f pozycjaGracz)
{
    pDownPressed = true;
    if(pozycjaGracz.y <= enemyPosition.y)
    {
       pUpPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
        enemySprite.setRotation(0);
    }
    if(pozycjaGracz.y > enemyPosition.y)
    {
        pDownPressed = true;
	pRightPressed = false;
	pLeftPressed = false;
        enemySprite.setRotation(180);
    }
    if(pozycjaGracz.x <= enemyPosition.x)
    {
        pLeftPressed = true;
	pUpPressed = false;
	pDownPressed = false;
        enemySprite.setRotation(-90);
    }
    if(pozycjaGracz.x > enemyPosition.x)
    {
        pRightPressed = true;
	pUpPressed = false;
	pDownPressed = false;
        enemySprite.setRotation(90);
    }

    //pColission();
    //enemyPosition.y += enemySpeed * elapsedTime;

	if (pRightPressed /*&& !(pRightCollision)*/)
	{
		enemyPosition.x += enemySpeed * elapsedTime;
	}
	if (pUpPressed /*&& !(pTopCollision)*/)
	{
		enemyPosition.y -= enemySpeed * elapsedTime;
	}
	if (pLeftPressed /*&& !(pLeftCollision)*/)
	{
		enemyPosition.x -= enemySpeed * elapsedTime;
	}
	if (pDownPressed /*&& !(pDownCollision)*/)
	{
		enemyPosition.y += enemySpeed * elapsedTime;
	}
    enemySprite.setPosition(enemyPosition);
}
Enemy::~Enemy()
{
}
