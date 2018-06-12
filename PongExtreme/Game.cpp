#include "stdafx.h"
#include "Game.h"

float fieldOfView = 45.0f;
float leftBarPosition = 0;
float rightBarPosition = 0;

bool upPressed = false;
bool downPressed = false;
bool wPressed = false;
bool sPressed = false;

Game::Game()
{
	this->shaderLoader = new ShaderLoader();
	this->objectLoader = new ObjectLoader();
	this->textureLoader = new TextureLoader();
}

Game::~Game()
{
	// delete this->window;
	// delete this->shaderLoader;
	// delete this->textureLoader;
	// delete this->objectLoader;
}

int Game::init()
{
	glewExperimental = true;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	glfwSetErrorCallback([](int error, const char * description) {
		Game game;
		game.logError(error, description);
	});
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(this->resolutionWidth, this->resolutionHeight, "Pong Extreme", NULL, NULL);
	if (this->window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(this->window);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
	// this->programId = this->shaderLoader->load("./resources/shaders/StandardShading.vertexshader", "./resources/shaders/StandardShading.fragmentshader");
	this->programId = this->shaderLoader->load("./resources/shaders/TransformVertexShader.vertexshader", "./resources/shaders/ColorFragmentShader.fragmentshader");
	// this->programId = this->shaderLoader->load("./resources/shaders/SimpleVertexShader.vertexshader", "./resources/shaders/SimpleFragmentShader.fragmentshader");
	glUseProgram(this->programId);


	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);

	// Hide the mouse and enable unlimited mouvement
	// glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	// glfwPollEvents();
	glfwSetCursorPos(this->window, this->resolutionWidth / 2, this->resolutionHeight / 2);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scanCode, int action, int mode) {
		Game game;
		game.onKeyPress(window, key, scanCode, action, mode);
	});

	glfwSetScrollCallback(window, [](GLFWwindow * window, double xOffset, double yOffset) {
		Game game;
		game.onMouseScroll(window, xOffset, yOffset);
	});
	// glfwSetMouseButtonCallback(widnow, new GLFWmousebuttonfun)


	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	glGenVertexArrays(1, &this->vertexArrayId);
	glBindVertexArray(this->vertexArrayId);

	return 0;
}

void Game::runMainLoop()
{
	LeftBar* leftBar = new LeftBar();
	RightBar* rightBar = new RightBar();
	leftBar->init();
	rightBar->init();

	do {
		this->preMainLoop();
		// ###################################################
		this->handleDraw(leftBar->draw(this->model, leftBarPosition));
		this->handleDraw(rightBar->draw(this->model, rightBarPosition));
		// ###################################################
		this->postMainLoop();
	} while (glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(this->window) == 0);
}

void Game::preMainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->generateMvp();
	this->handleKeys();
}

void Game::postMainLoop()
{
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}

void Game::computeMatricesFromInputs()
{
}

glm::mat4 Game::getProjectionMatrix()
{
	return this->projection;
}

glm::mat4 Game::getViewMatrix()
{
	return this->view;
}

void Game::test()
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.

	this->objectLoader->load("./resources/objects/dragon.obj", vertices, uvs, normals);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}

void Game::sendMvp() {
	this->mvp = this->projection * this->view * this->model;
	glUniformMatrix4fv(glGetUniformLocation(this->programId, "MVP"), 1, GL_FALSE, &this->mvp[0][0]);
}

void Game::handleDraw(glm::mat4 model)
{
	this->savedModel = this->model;
	this->model = model;
	this->sendMvp();
	this->model = this->savedModel;
}

void Game::generateMvp() {

	this->projection = glm::perspective(
		glm::radians(fieldOfView),
		(float)this->resolutionWidth / (float)this->resolutionHeight,
		0.1f,
		100.0f
	);
	this->view = glm::lookAt(
		glm::vec3(25, 25, 0),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
	this->model = glm::mat4(1.0f);
	this->mvp = this->projection * this->view * this->model;
}

void Game::onKeyPress(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	key == GLFW_KEY_UP && action == GLFW_PRESS && (upPressed = true);
	key == GLFW_KEY_UP && action == GLFW_RELEASE && (upPressed = false);

	key == GLFW_KEY_DOWN && action == GLFW_PRESS && (downPressed = true);
	key == GLFW_KEY_DOWN && action == GLFW_RELEASE && (downPressed = false);

	key == GLFW_KEY_W && action == GLFW_PRESS && (wPressed = true);
	key == GLFW_KEY_W && action == GLFW_RELEASE && (wPressed = false);

	key == GLFW_KEY_S && action == GLFW_PRESS && (sPressed = true);
	key == GLFW_KEY_S && action == GLFW_RELEASE && (sPressed = false);
}

void Game::onMouseKeyPress(GLFWwindow * window, int button, int action, int mods)
{
}

void Game::onMouseCursorMove(GLFWwindow * window, double xPosition, double yPosition)
{
	printf("Position: (%f, %f)\n", xPosition, yPosition);
}

void Game::onMouseScroll(GLFWwindow * window, double xOffset, double yOffset)
{
	fieldOfView -= yOffset;
}

void Game::logError(int error, const char * description)
{
	fputs(description, stderr);
	printf("Error %d: %s \n", error, description);
}

void Game::handleKeys()
{
	const float modifier = 0.1f;

	wPressed && (leftBarPosition -= modifier);
	sPressed && (leftBarPosition += modifier);
	upPressed && (rightBarPosition -= modifier);
	downPressed && (rightBarPosition += modifier);
}
