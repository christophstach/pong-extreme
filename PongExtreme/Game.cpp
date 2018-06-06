#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

Game::~Game()
{
	delete this->window;
	delete this->programId;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("Key pressed!key_callback\n");
}

int Game::init()
{
	glfwInit() || fprintf(stderr, "Failed to initialize GLFW");
	glfwSetErrorCallback(logError);

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	this->window = glfwCreateWindow(1024, 768, "Pong Extreme", NULL, NULL);

	if (!this->window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->window);
	glewExperimental = true; // Needed for core profile

	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glfwSetKeyCallback(this->window, onKeyPress);
	//std::bind(std::bind(this->window, &Game::onKeyPress), glfwSetKeyCallback);
	//glfwSetKeyCallback(this->window, key_callback);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	printf("Finished initializing...\n");
	return 0;
}

void Game::runMainLoop()
{
	printf("Running main loop...\n");
	while (!glfwWindowShouldClose(this->window))
	{
		glfwSwapBuffers(this->window); // Swap buffers
		glfwPollEvents(); // Poll for and process events 
	}
}

void Game::drawLeftBar()
{
}

void Game::drawRightBar()
{
}

void Game::drawBall()
{
}

void logError(int error, const char * description)
{
	fputs(description, stderr);
	printf("Error %d: %s \n", error, description);
}

void onKeyPress(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		printf("Key pressed!\n");
	}
}
