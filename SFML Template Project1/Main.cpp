#include "Game.h"

int main()
{
	//Seeding RNG
	srand(time(NULL));
	Game ourGame;
	ourGame.Run();
	return 0;
}