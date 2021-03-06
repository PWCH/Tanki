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

    //okreslenie kierunku
    //int kierunek;

	//Porusza gracza w okre�lonym kierunku
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//Zatrzymuje gracza w okre�lonym kierunku
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//Funkcja wywo�ywana co klatk�
	void update(float elapsedTime);

	//Sprawdzenie kolizji
	bool pColission();

	//Pozycja gracza
	Vector2f pPosition;

private:

	Sprite pSprite;

	//Tekstura gracza
	Texture pTexture;

	//Kierunek poruszania gracza
	bool pLeftPressed;
	bool pRightPressed;
	bool pUpPressed;
	bool pDownPressed;

	//Kolizja do warunk�w
	bool pLeftCollision;
	bool pRightCollision;
	bool pTopCollision;
	bool pDownCollision;

	//Pr�dko�� gracza w px na sekund�
	float pSpeed;
};

