#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(bool = true);
	~Entity();

	//Zabezpiecznie przed wzajemnym zabijaniem
	bool killPlayer;
private:

};