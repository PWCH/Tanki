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
	
	void update(float elapsedTime);

	~Enemy();
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
	Sprite arrEnemy[];

};

