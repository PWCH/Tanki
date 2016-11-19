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
	//Kombinacyjne poruszanie gracza
	/*void moveDownLeft();
	void moveDownRight();*/
	//Zatrzymuje gracza w okreœlonym kierunku
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//Funkcja wywo³ywana co klatkê
	void update(float elapsedTime);
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

	//Prêdkoœæ gracza w px na sekundê
	float pSpeed;
};

