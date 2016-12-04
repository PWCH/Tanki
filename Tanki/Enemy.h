#pragma
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Enemy
{
public:
	Enemy();

	//Generowanie przeciwników
	Sprite generateEnemy();

	//Zabicie przeciwnika
	void killEnemy();

	void update(float elapsedTime, Vector2f pozycjaGracz);

	~Enemy();

	bool pColission();

private:

	//Liczba przeciwników
	int noEnemies;

	//Pozycja przeciwnika
	Vector2f enemyPosition;

	//Sprite przeciwnika
	Sprite enemySprite;

	//Tekstura przeciwnika
	Texture enemyTexture;

	//Prêdkoœæ przeciwnika
	float enemySpeed;

	//????Tablica przeciwników
	Sprite arrEnemy[3];

	//Kierunek poruszania gracza
	bool pLeftPressed;
	bool pRightPressed;
	bool pUpPressed;
	bool pDownPressed;

	//Kolizja do warunków
	bool pLeftCollision;
	bool pRightCollision;
	bool pTopCollision;
	bool pDownCollision;
};

