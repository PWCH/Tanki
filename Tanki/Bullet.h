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

	//Dodawanie pocisk�w
	void addBullet(Vector2f, Vector2f);

	//Usuwanie pocisk�w
	void removeBullet(int it);

	//Aktualizacja pocisk�w
	void update();
private:
	//Pozycja gracza
	Vector2f bulletPosition;

	//Sprite pocisku
	Sprite bulletSprite;

	//Tekstura pocisku
	Texture bulletTexture;
};

