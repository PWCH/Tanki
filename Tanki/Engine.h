#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Engine
{
public:
	Engine();
	~Engine();
	//start wywo�a wszystkie prywatne funkcje
	void start();
private:
	RenderWindow gameWindow;
	//Deklaracja sprite i tekstury t�a
	Sprite gameBackgroudSprite;
	Texture gameBackgroudTexture;

	//Inicjacja gracza
	Player pPlayer;

	//Prywatne funckje tylko do u�ytku wewn�trznego
	void input();
	void update(float dtAsSeconds);
	void draw();
};
