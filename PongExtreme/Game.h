#pragma once

void logError(int error, const char* description);
void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);

class Game
{
private:
	const int resolutionWidth = 1440;
	const int resolutionHeight = 900;
	GLFWwindow * window;
	GLuint programId;
	ShaderLoader* shaderLoader;
	TextureLoader* textureLoader;
	ObjectLoader* objectLoader;
	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 mvp;
	GLuint vertexArrayId;

public:
	Game();
	~Game();

	int init();
	void generateMvp();
	void sendMvp();
	void runMainLoop();
	void preMainLoop();
	void postMainLoop();

	void drawLeftBar();
	void drawRightBar();
	void drawBall();
};

