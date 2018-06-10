#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	this->shaderLoader = new ShaderLoader();
	this->objectLoader = new ObjectLoader();
	this->textureLoader = new TextureLoader();
}

Game::~Game()
{
	delete this->window;
	delete this->shaderLoader;
	delete this->textureLoader;
	delete this->objectLoader;
}

int Game::init()
{
	// Initialise GLFW
	glewExperimental = true; // Needed for core profile
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	glfwSetErrorCallback(this->logError);
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
	// glfwSetCursorPos(this->window, this->resolutionWidth / 2, this->resolutionHeight / 2);

	/*glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scanCode, int action, int mode) {

	});*/

	glfwSetKeyCallback(window, this->onKeyPress);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	glGenVertexArrays(1, &this->vertexArrayId);
	glBindVertexArray(this->vertexArrayId);

	this->generateMvp();

	return 0;
}

void Game::runMainLoop()
{
	// float FoV = initialFoV - 5 * glfwGetMouseWheel();
	Cube* cube = new Cube();
	cube->init();

	do {
		this->preMainLoop();
		// ###################################################
		cube->draw();
		// ###################################################
		this->postMainLoop();
	} while (glfwGetKey(this->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(this->window) == 0);
}

void Game::preMainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void Game::postMainLoop()
{
	this->sendMvp();
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}

void Game::sendMvp() {
	this->mvp = this->projection * this->view * this->model;
	glUniformMatrix4fv(glGetUniformLocation(this->programId, "MVP"), 1, GL_FALSE, &this->mvp[0][0]);
}

void Game::generateMvp() {
	this->projection = glm::perspective(glm::radians(45.0f), (float)this->resolutionWidth / (float)this->resolutionHeight, 0.1f, 100.0f);
	this->view = glm::lookAt(
		glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	this->model = glm::mat4(1.0f);
	this->mvp = this->projection * this->view * this->model;
}



void Game::onKeyPress(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	key == GLFW_KEY_UP && action == GLFW_PRESS && printf("UP\n");
	key == GLFW_KEY_DOWN && action == GLFW_PRESS && printf("DOWN\n");
	key == GLFW_KEY_LEFT && action == GLFW_PRESS && printf("LEFT\n");
	key == GLFW_KEY_RIGHT && action == GLFW_PRESS && printf("RIGHT\n");

	key == GLFW_KEY_W && action == GLFW_PRESS && printf("W\n");
	key == GLFW_KEY_S && action == GLFW_PRESS && printf("S\n");
	key == GLFW_KEY_A && action == GLFW_PRESS && printf("A\n");
	key == GLFW_KEY_D && action == GLFW_PRESS && printf("D\n");
}

void Game::logError(int error, const char * description)
{
	fputs(description, stderr);
	printf("Error %d: %s \n", error, description);
}
