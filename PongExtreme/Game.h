#pragma once


class Game
{
public:
	Game();
	~Game();

	void init();
	void runMainLoop();

private:
	const int resolutionWidth = 1440;
	const int resolutionHeight = 900;

	GLuint vaos[NumberVaos];
	GLuint taos[NumberTaos];

	GLuint shaderId;
	GLFWwindow * window;
	ShaderLoader* shaderLoader;
	TextureLoader* textureLoader;
	ObjectLoader* objectLoader;

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 mvp;


	void onKeyPress(GLFWwindow* window, int key, int scanCode, int action, int mods);
	void onMouseButtonClick(GLFWwindow* window, int button, int action, int mods);
	void onMouseCursorMove(GLFWwindow* window, double xPosition, double yPosition);
	void onMouseScroll(GLFWwindow* window, double xOffset, double yOffset);
	void logError(int error, const char * description);
	void handleKeys();

	void generateMvp();
	void sendMvp();
	void handleDraw(ThreeDimensional* threeDimensional, GLuint texture);

	void preMainLoop();
	void postMainLoop();
};