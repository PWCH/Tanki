#include "Engine.h"

using namespace sf;

void Engine::update(float timeAsSeconds)
{
	pPlayer.update(timeAsSeconds);
	for(int i = playerBullets.size()-1; i > 0; --i)
        playerBullets[i].update(timeAsSeconds);
}
