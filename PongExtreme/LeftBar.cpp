#include "stdafx.h"
#include "LeftBar.h"


LeftBar::LeftBar()
{
	this->cube = new Cube();
}


LeftBar::~LeftBar()
{
}

void LeftBar::init()
{
	this->cube->init();
}

glm::mat4 LeftBar::draw(glm::mat4 model, float position)
{
	this->cube->draw();
	model = glm::translate(model, glm::vec3(position, 0.0f, 16.0f));
	model = glm::scale(model, glm::vec3(4.0f, 0.8f, 0.2f));
	return model;
}
