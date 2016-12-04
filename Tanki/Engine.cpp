#include "Engine.h"

Engine::Engine()
{
	//Pobiera rozdzielczosc ekranu, tworzy okno gry
	Vector2f resolution;
	resolution.x = 800;
	resolution.y = 600;

	gameWindow.create(VideoMode(resolution.x, resolution.y), "Tank Game");
	//sf::RenderWindow gameWindow(sf::VideoMode(resolution.x, resolution.y), "SFML works!");

	//£aduje teksturê t³a
	gameBackgroudTexture.loadFromFile("data/background.png");
	//Wczytanie tekstury pocisku
	if (!(bulletTexture.loadFromFile("data/bullet.png")))
	{
		cout << "Nie zaladowano tekstury pocisku";
	}
	gameBackgroudSprite.setTexture(gameBackgroudTexture);

	//sf::Window::setKeyRepeatEnabled(false);
	gameWindow.setKeyRepeatEnabled(false);
}

void Engine::start()
{
	Clock clock;

	while (gameWindow.isOpen())
	{
	    //reset przelacznikow
		tylkoRaz++;

		//Restart zegara i przypisanie czasu do time
		Time time = clock.restart();

		float timeAsSeconds = time.asSeconds();

		input();
		update(timeAsSeconds);
		draw();


	}

}

Engine::~Engine()
{
}
