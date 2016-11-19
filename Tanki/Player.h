#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player : public Transformable 
{
public:
	Player();
	~Player();

	//Wysy�a kopi� sprite do main
	Sprite getSprite();

	//Porusza gracza w okre�lonym kierunku
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	//Kombinacyjne poruszanie gracza
	/*void moveDownLeft();
	void moveDownRight();*/
	//Zatrzymuje gracza w okre�lonym kierunku
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//Funkcja wywo�ywana co klatk�
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

	//Pr�dko�� gracza w px na sekund�
	float pSpeed;
};

