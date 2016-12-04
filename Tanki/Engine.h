#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace sf;

class Engine
{
public:
	Engine();
	~Engine();
	//start wywo�a wszystkie prywatne funkcje
	void start();

	int kierunek;

    int tylkoRaz = 0;

private:
	RenderWindow gameWindow;
	//Deklaracja sprite i tekstury t�a
	Sprite gameBackgroudSprite;
	Texture gameBackgroudTexture;
	Texture bulletTexture;

	//Inicjacja gracza
	Player pPlayer;

	//Inicjacja przeciwnika
	//Enemy enemy;

	//Inicjacja pocisk�w gracza
	vector <Bullet> playerBullets;
	//Bullet playerBullets;

	//Prywatne funckje tylko do u�ytku wewn�trznego
	void input();
	void update(float dtAsSeconds);
	void draw();
};

