#pragma
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Enemy
{
public:
	Enemy();

	//Generowanie przeciwnik�w
	Sprite generateEnemy();

	//Zabicie przeciwnika
	void killEnemy();

	void update(float elapsedTime, Vector2f pozycjaGracz);

	~Enemy();

	bool pColission();

private:

	//Liczba przeciwnik�w
	int noEnemies;

	//Pozycja przeciwnika
	Vector2f enemyPosition;

	//Sprite przeciwnika
	Sprite enemySprite;

	//Tekstura przeciwnika
	Texture enemyTexture;

	//Pr�dko�� przeciwnika
	float enemySpeed;

	//????Tablica przeciwnik�w
	Sprite arrEnemy[3];

	//Kierunek poruszania gracza
	bool pLeftPressed;
	bool pRightPressed;
	bool pUpPressed;
	bool pDownPressed;

	//Kolizja do warunk�w
	bool pLeftCollision;
	bool pRightCollision;
	bool pTopCollision;
	bool pDownCollision;
};

