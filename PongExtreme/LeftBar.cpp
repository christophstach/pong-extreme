#include "stdafx.h"
#include "LeftBar.h"


LeftBar::LeftBar(GLuint vao)
{
	this->vao = vao;
	this->cube = new Cube(this->vao);
}

glm::mat4 LeftBar::transform(glm::mat4 model) 
{
	model = glm::translate(model, glm::vec3(this->position, 0.0f, 16.0f));
	model = glm::scale(model, glm::vec3(4.0f, 0.8f, 0.2f));
	return model;
}

void LeftBar::setPosition(float position)
{
	this->position = position;
}

void LeftBar::draw()
{
	this->cube->draw();
}
