#include "stdafx.h"
#include "Ball.h"

Ball::Ball(GLuint vao)
{
	this->vao = vao;
	this->sphere = new Sphere(this->vao, 50, 50);
}

glm::mat4 Ball::transform(glm::mat4 model)
{
	return model;
}

void Ball::draw()
{
	this->sphere->draw();
}


