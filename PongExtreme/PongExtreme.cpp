// PongExtreme.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{	
	Game game = Game();

	game.init();
	game.runMainLoop();
	return 0;
}

