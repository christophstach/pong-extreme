// PongExtreme.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	
	Game game = Game();

	if (game.init() == -1) {
		return -1;
	}

	game.runMainLoop();
	return 0;
}

