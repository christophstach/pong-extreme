#include "stdafx.h"
#include "LeftBar.h"


LeftBar::LeftBar(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
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
	this->object->draw();
}
