#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <vector>

using namespace sf;

class Bullet : Enemy

{
public:
	Bullet(bool = true);
	~Bullet();

	//Dodawanie pocisków
	void addBullet(Vector2f, Vector2f);

	//Usuwanie pocisków
	void removeBullet(int it);

	//Aktualizacja pocisków
	void update();
private:
	//Pozycja gracza
	Vector2f bulletPosition;

	//Sprite pocisku
	Sprite bulletSprite;

	//Tekstura pocisku
	Texture bulletTexture;
};

