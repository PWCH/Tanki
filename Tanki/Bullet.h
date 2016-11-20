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

	//Dodawanie pocisk�w
	void addBullet();

	//Usuwanie pocisk�w
	void removeBullet(int it);

	//Aktualizacja pocisk�w
	void update();

private:
	//Pozycja pocisku
	Vector2f bulletPosition;

	//Sprite pocisku
	Sprite bulletSprite;

	//Tekstura pocisku
	Texture bulletTexture;

	//Vector przechowuj�cy wszyskie pociski
	vector <Bullet> allBullets;

	//Pr�dko�� pocisku
	float bulletSpeed;
};

