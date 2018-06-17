#include "stdafx.h"
#include "Game.h"

float fieldOfView = 60.0f;
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

void Game::init()
{
	glewExperimental = true;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}

	glfwSetErrorCallback([](int error, const char * description) {
		Game game;
		game.logError(error, description);
	});

	this->window = glfwCreateWindow(this->resolutionWidth, this->resolutionHeight, "Pong Extreme", NULL, NULL);
	if (this->window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->window);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}

	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
	this->programId = this->shaderLoader->load("./resources/shaders/StandardShading.vertexshader", "./resources/shaders/StandardShading.fragmentshader");

	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
	//glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(this->window, this->resolutionWidth / 2, this->resolutionHeight / 2);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scanCode, int action, int mods) {
		Game game;
		game.onKeyPress(window, key, scanCode, action, mods);
	});

	glfwSetScrollCallback(window, [](GLFWwindow * window, double xOffset, double yOffset) {
		Game game;
		game.onMouseScroll(window, xOffset, yOffset);
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
		Game game;
		game.onMouseButtonClick(window, button, action, mods);
	});


	glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);

	glGenVertexArrays(NumberVaos, this->vaos);
}

void Game::runMainLoop()
{
	
	LeftBar* leftBar = new LeftBar(this->vaos[Vao::LeftBarObject]);
	RightBar* rightBar = new RightBar(this->vaos[Vao::RightBarObject]);
	ThreeDimensional* ball = new Ball(this->vaos[Vao::BallObject]);
	ThreeDimensional* lamp = new Lamp(this->vaos[Vao::LampObject]);
	
	Arena* arena = new Arena(this->vaos[Vao::ArenaObject], this->objectLoader, this->textureLoader);

	do {
		this->preMainLoop();
		// ###################################################
		leftBar->setPosition(leftBarPosition);
		rightBar->setPosition(rightBarPosition);

		this->handleDraw(arena);
		this->handleDraw(leftBar);
		this->handleDraw(rightBar);
		this->handleDraw(ball);
		this->handleDraw(lamp);
		
		// ###################################################
		this->postMainLoop();
	} while (glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(this->window) == 0);
}

void Game::preMainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(this->programId);
	glLoadIdentity();

	this->generateMvp();
	this->handleKeys();
}

void Game::postMainLoop()
{
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}

void Game::sendMvp() {
	this->mvp = this->projection * this->view * this->model;

	glUniformMatrix4fv(glGetUniformLocation(this->programId, "MVP"), 1, GL_FALSE, &this->mvp[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->programId, "M"), 1, GL_FALSE, &this->model[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->programId, "V"), 1, GL_FALSE, &this->view[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->programId, "P"), 1, GL_FALSE, &this->projection[0][0]);
}

void Game::handleDraw(ThreeDimensional* threeDimensional)
{
	this->model = threeDimensional->transform(this->model);
	this->sendMvp();
	this->model = glm::mat4(1.0f);
	threeDimensional->draw();
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
	glm::vec3 lightPos = glm::vec3(0, 5, 0);
	glUniform3f(glGetUniformLocation(this->programId, "LightPosition_worldspace"), lightPos.x, lightPos.y, lightPos.z);
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


void Game::onMouseButtonClick(GLFWwindow * window, int button, int action, int mods)
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
