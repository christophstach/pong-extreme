#pragma once

class Game
{
public:
	Game();
	~Game();

	int init();
	void runMainLoop();
	void drawLeftBar();
	void drawRightBar();
	void drawBall();
};

