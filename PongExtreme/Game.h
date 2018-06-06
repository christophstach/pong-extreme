#pragma once

void logError(int error, const char* description);
void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);

class Game
{
private:
	GLFWwindow * window;
	GLuint* programId;
	ShaderLoader* shaderLoader;
	TextureLoader* textureLoader;
	ObjectLoader* objectLoader;
public:
	Game();
	~Game();

	int init();
	void runMainLoop();
	void drawLeftBar();
	void drawRightBar();
	void drawBall();
};

