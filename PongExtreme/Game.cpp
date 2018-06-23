#include "stdafx.h"
#include "Game.h"

float fieldOfView = 60.0;
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
	this->shaderId = this->shaderLoader->load("./resources/shaders/StandardShading.vertexshader", "./resources/shaders/StandardShading.fragmentshader");

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
	glUseProgram(this->shaderId);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(this->shaderId, "myTextureSampler"), 0);
}

void Game::runMainLoop()
{
	this->taos[Tao::BallTexture] = this->textureLoader->loadStb("./resources/textures/ball.png", GL_REPEAT);
	this->taos[Tao::FlatBlueGreyTexture] = this->textureLoader->loadStb("./resources/textures/flat/blue-grey.png");
	this->taos[Tao::FlatFlirtatiousTexture] = this->textureLoader->loadStb("./resources/textures/flat/flirtatious.png");
	this->taos[Tao::FlatFusionRedTexture] = this->textureLoader->loadStb("./resources/textures/flat/fusion-red.png");
	this->taos[Tao::FlatHighBlueTexture] = this->textureLoader->loadStb("./resources/textures/flat/high-blue.png");
	this->taos[Tao::FlatMaximumBlueGreenTexture] = this->textureLoader->loadStb("./resources/textures/flat/maximum-blue-green.png");
	this->taos[Tao::FlatOrangeHibiscusTexture] = this->textureLoader->loadStb("./resources/textures/flat/orange-hibiscus.png");
	this->taos[Tao::FlatReptileGreenTexture] = this->textureLoader->loadStb("./resources/textures/flat/reptile-green.png");


	Floor* floor = new Floor(this->objectLoader, this->vaos[Vao::FloorObject]);
	LeftBar* leftBar = new LeftBar(this->objectLoader, this->vaos[Vao::LeftBarObject]);
	RightBar* rightBar = new RightBar(this->objectLoader, this->vaos[Vao::RightBarObject]);
	Ball* ball = new Ball(this->objectLoader, this->vaos[Vao::BallObject]);

	ArenaBoundaryTop* arenaBoundaryTop = new ArenaBoundaryTop(this->objectLoader, this->vaos[Vao::ArenaBoundaryTopObject]);
	ArenaBoundaryRight* arenaBoundaryRight = new ArenaBoundaryRight(this->objectLoader, this->vaos[Vao::ArenaBoundaryRightObject]);
	ArenaBoundaryBottom* arenaBoundaryBottom = new ArenaBoundaryBottom(this->objectLoader, this->vaos[Vao::ArenaBoundaryBottomObject]);
	ArenaBoundaryLeft* arenaBoundaryLeft = new ArenaBoundaryLeft(this->objectLoader, this->vaos[Vao::ArenaBoundaryLeftObject]);

	ball
		->setArenaBoundaryTop(arenaBoundaryTop)
		->setArenaBoundaryRight(arenaBoundaryRight)
		->setArenaBoundaryBottom(arenaBoundaryBottom)
		->setArenaBoundaryLeft(arenaBoundaryLeft)
		->setLeftBar(leftBar)
		->setRightBar(rightBar);


	do {
		this->preMainLoop();
		// ###################################################
		leftBar->setPosition(leftBarPosition);
		rightBar->setPosition(rightBarPosition);

		this->handleDraw(floor, this->taos[Tao::FlatBlueGreyTexture]);

		this->handleDraw(arenaBoundaryTop, this->taos[Tao::FlatFlirtatiousTexture]);
		this->handleDraw(arenaBoundaryRight, this->taos[Tao::FlatFlirtatiousTexture]);
		this->handleDraw(arenaBoundaryBottom, this->taos[Tao::FlatFlirtatiousTexture]);
		this->handleDraw(arenaBoundaryLeft, this->taos[Tao::FlatFlirtatiousTexture]);

		this->handleDraw(leftBar, this->taos[Tao::FlatFusionRedTexture]);
		this->handleDraw(rightBar, this->taos[Tao::FlatHighBlueTexture]);

		this->handleDraw(ball, this->taos[Tao::BallTexture]);
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

void Game::sendMvp() {
	this->mvp = this->projection * this->view * this->model;
	glm::vec3 lightPosition = glm::vec3(10.0, 20.0, 0.0);

	glUniformMatrix4fv(glGetUniformLocation(this->shaderId, "MVP"), 1, GL_FALSE, &this->mvp[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->shaderId, "M"), 1, GL_FALSE, &this->model[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->shaderId, "V"), 1, GL_FALSE, &this->view[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->shaderId, "P"), 1, GL_FALSE, &this->projection[0][0]);
	glUniform3f(glGetUniformLocation(this->shaderId, "LightPosition_worldspace"), lightPosition.x, lightPosition.y, lightPosition.z);
}

void Game::handleDraw(GameObject* gameObject, GLuint texture)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	this->model = gameObject->transform(this->model);
	this->sendMvp();
	this->model = glm::mat4(1.0f);
	gameObject->draw();
}

void Game::generateMvp() {
	const float cameraHeight = 25;

	this->projection = glm::perspective(
		glm::radians(fieldOfView),
		(float)this->resolutionWidth / (float)this->resolutionHeight,
		0.1f,
		100.0f
	);

	this->view = glm::lookAt(
		glm::vec3(25, cameraHeight, 0),
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
