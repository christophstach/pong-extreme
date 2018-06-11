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
	glm::mat4 mvp;
	GLuint vertexArrayId;

	glm::vec3 position = glm::vec3(0, 0, 5);
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float initialFieldofView = 45.0f;
	float speed = 3.0f;
	float mouseSpeed = 0.005f;


	void onKeyPress(GLFWwindow* window, int key, int scanCode, int action, int mode);
	void logError(int error, const char * description);

	void generateMvp();
	void sendMvp();

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

