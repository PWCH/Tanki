#include "Enemy.h"

Enemy::Enemy()
{
	//Liczba przeciwników
	noEnemies = 5;

	//Wczytanie tekstury przeciwnika
	if (!(enemyTexture.loadFromFile("data/enemy.png")))
	{
		cout << "Nie zaladowano tekstury przeciwnika";
	}
	enemySprite.setTexture(enemyTexture);

	//Ustawienie punktu zaczepienia przecinika
	Vector2u enemySize = enemyTexture.getSize();
	enemySprite.setOrigin(enemySize.x / 2, enemySize.y / 2);

	enemyPosition.x = 200;
	enemyPosition.y = 200;
	enemySprite.setPosition(enemyPosition);
}

Sprite Enemy::generateEnemy()
{
	return enemySprite;
}

void Enemy::update(float elapsedTime)
{
		enemyPosition.x  += enemySpeed * elapsedTime;
		enemyPosition.y += enemySpeed * elapsedTime;
		enemySprite.setPosition(enemyPosition);
}
Enemy::~Enemy()
{
}
