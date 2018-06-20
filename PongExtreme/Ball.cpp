#include "stdafx.h"
#include "Ball.h"

Ball::Ball(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/ball2.obj");
}

glm::mat4 Ball::transform(glm::mat4 model)
{
	this->rotation += 0.01;
	
	model = glm::rotate(model, this->rotation, glm::vec3(1.0f, 1.0f, 1.0f));
	//model = glm::translate(model, glm::vec3(0.0, 0.0, -0.75));
	model = glm::scale(model, glm::vec3(0.75f, 0.75f, 0.75f));
	return model;
}

void Ball::draw()
{
	this->object->draw();
}


