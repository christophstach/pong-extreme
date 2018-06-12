#pragma once


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
	glm::mat4 savedModel;
	glm::mat4 mvp;
	GLuint vertexArrayId;

	glm::vec3 position = glm::vec3(0, 0, 5);
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float speed = 3.0f;
	float mouseSpeed = 0.005f;


	void onKeyPress(GLFWwindow* window, int key, int scanCode, int action, int mods);
	void onMouseKeyPress(GLFWwindow* window, int button, int action, int mods);
	void onMouseCursorMove(GLFWwindow* window, double xPosition, double yPosition);
	void onMouseScroll(GLFWwindow* window, double xOffset, double yOffset);
	void logError(int error, const char * description);
	void handleKeys();

	void generateMvp();
	void sendMvp();
	void handleDraw(glm::mat4 model);

	void preMainLoop();
	void postMainLoop();

	void computeMatricesFromInputs();
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();

	void test();

public:
	Game();
	~Game();

	int init();
	void runMainLoop();
};

