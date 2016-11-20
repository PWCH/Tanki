#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player : public Transformable 
{
public:
	Player();
	~Player();

	//Wysy³a kopiê sprite do main
	Sprite getSprite();

	//Porusza gracza w okreœlonym kierunku
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//Zatrzymuje gracza w okreœlonym kierunku
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//Funkcja wywo³ywana co klatkê
	void update(float elapsedTime);

	//Sprawdzenie kolizji 
	bool pColission();
private:
	//Pozycja gracza
	Vector2f pPosition;

	Sprite pSprite;

	//Tekstura gracza
	Texture pTexture;

	//Kierunek poruszania gracza 
	bool pLeftPressed;
	bool pRightPressed;
	bool pUpPressed;
	bool pDownPressed;
	
	//Kolizja do warunków
	bool collision;
	//Prêdkoœæ gracza w px na sekundê
	float pSpeed;
};

