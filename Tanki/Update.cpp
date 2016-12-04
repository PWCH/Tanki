#include "Engine.h"

using namespace sf;

void Engine::update(float timeAsSeconds)
{
    //Bullet bullet(kierunek, pPlayer.pPosition);
    //usuwanie pociskow
    for (int i = playerBullets.size() - 1; i > 0; --i)
    {
        if(playerBullets[i].removeBullet() == false)
        {
            playerBullets[0] = playerBullets[i];
            playerBullets[i]=playerBullets[playerBullets.size()-1];
            playerBullets[playerBullets.size()-1] = playerBullets[0];

            playerBullets.pop_back();
        }
       // cout << "\n\njest do usuniecia\n\n";
    }

    pPlayer.update(timeAsSeconds);
    for(int i = playerBullets.size()-1; i > 0; --i)
        playerBullets[i].update(timeAsSeconds);
}
