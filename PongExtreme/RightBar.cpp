#include "stdafx.h"
#include "RightBar.h"


RightBar::RightBar()
{
	this->cube = new Cube();
}


RightBar::~RightBar()
{
}

void RightBar::init()
{
	this->cube->init();
}

glm::mat4 RightBar::draw(glm::mat4 model, float position)
{
	this->cube->draw();
	model = glm::translate(model, glm::vec3(position, 0.0f, -16.0f));
	model = glm::scale(model, glm::vec3(4.0f, 0.8f, 0.2f));
	return model;
}
