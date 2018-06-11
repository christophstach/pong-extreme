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

glm::mat4 RightBar::draw(glm::mat4 model)
{
	this->cube->draw();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -8.0f));
	model = glm::scale(model, glm::vec3(5.0f, 1.0f, 1.0f));
	return model;
}
