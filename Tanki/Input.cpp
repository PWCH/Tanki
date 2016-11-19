#include "Engine.h"

void Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		gameWindow.close();
	}
	// Czytanie ruchu gracza
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		pPlayer.moveUp();
	}
	else
	{
		pPlayer.stopUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		pPlayer.moveDown();
	}
	else
	{
		pPlayer.stopDown();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		pPlayer.moveLeft();
	}
	else
	{
		pPlayer.stopLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		pPlayer.moveRight();
	}
	else
	{
		pPlayer.stopRight();
	}
}