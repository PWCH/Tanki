#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Bullet : Entity

{
public:

    //okreslenie kierunku wystrzalu
	enum Kierunek {UP, DOWN, LEFT, RIGHT} kierunk;

	Bullet(int kierunek, Vector2f pozycjaGracza/*Kierunek kierunek, Texture *bulletTexture*/);
	~Bullet();

	//Dodawanie pocisków
	void addBullet();

	//Usuwanie pocisków
	bool removeBullet();

	//Aktualizacja pocisków
	void update();

	//Wysyla kopie sprite do main
	Sprite getSprite();

	//Funkcja wywo³ywana co klatkê
	void update(float elapsedTime);

	//sprawdzanie kolizji
	bool bulletColission();

	void moveBullets();

	//przelacznik strzelania
	//bool switchBullet;

private:
	//Pozycja pocisku
	Vector2f bulletPosition;

	//Sprite pocisku
	Sprite bulletSprite;

	//Tekstura pocisku
	Texture bulletTexture;

	//Vector przechowujacy wszyskie pociski
	vector <Bullet> allBullets;

	//Prêdkoœæ pocisku
	float bulletSpeed;

	//Kierunek poruszania gracza
	bool pLeftPressed = false;
	bool pRightPressed = false;
	bool pUpPressed = false;
	bool pDownPressed = false;

	//Kolizja do warunków
	bool pLeftCollision;
	bool pRightCollision;
	bool pTopCollision;
	bool pDownCollision;
};

