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

	GLFWwindow * window = nullptr;
	ShaderLoader* shaderLoader = nullptr;
	TextureLoader* textureLoader = nullptr;
	ObjectLoader* objectLoader = nullptr;

	Floor* floor = nullptr;
	LeftBar* leftBar = nullptr;
	RightBar* rightBar = nullptr;
	Ball* ball = nullptr;

	ArenaBoundaryTop* arenaBoundaryTop = nullptr;
	ArenaBoundaryRight* arenaBoundaryRight = nullptr;
	ArenaBoundaryBottom* arenaBoundaryBottom = nullptr;
	ArenaBoundaryLeft* arenaBoundaryLeft = nullptr;

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 mvp;
	std::chrono::high_resolution_clock::time_point timePrevious;
	GLdouble timeDelta = 0;


	void onKeyPress(GLFWwindow* window, int key, int scanCode, int action, int mods);
	void onMouseButtonClick(GLFWwindow* window, int button, int action, int mods);
	void onMouseCursorMove(GLFWwindow* window, double xPosition, double yPosition);
	void onMouseScroll(GLFWwindow* window, double xOffset, double yOffset);
	void logError(int error, const char * description);
	void handleKeys();

	void generateMvp();
	void sendMvp();
	void handleDraw(GameObject* gameObject, GLuint texture);

	void preMainLoop();
	void postMainLoop();
	GLdouble getTimeDelta();
};