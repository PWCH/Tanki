#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(bool = true);
	~Enemy();

	//Zabezpiecznie przed wzajemnym zabijaniem
	bool killPlayer;
private:

};