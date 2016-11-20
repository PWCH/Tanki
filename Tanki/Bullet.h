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
	Bullet(bool = true);
	~Bullet();

	//Dodawanie pocisków
	void addBullet();

	//Usuwanie pocisków
	void removeBullet(int it);

	//Aktualizacja pocisków
	void update();

private:
	//Pozycja pocisku
	Vector2f bulletPosition;

	//Sprite pocisku
	Sprite bulletSprite;

	//Tekstura pocisku
	Texture bulletTexture;

	//Vector przechowuj¹cy wszyskie pociski
	vector <Bullet> allBullets;

	//Prêdkoœæ pocisku
	float bulletSpeed;
};

