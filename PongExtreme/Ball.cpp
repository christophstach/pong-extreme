#include "stdafx.h"
#include "Ball.h"

Ball::Ball(GLuint programId, GLuint vao, ObjectLoader* objectLoader)
{
	this->programId = programId;
	this->vao = vao;
	this->object = new ThreeDimensionalObject(this->programId,  this->vao, "./resources/objects/sphere.obj", NULL, objectLoader);
}

glm::mat4 Ball::transform(glm::mat4 model)
{
	return model;
}

void Ball::draw()
{
	this->object->draw();
}


