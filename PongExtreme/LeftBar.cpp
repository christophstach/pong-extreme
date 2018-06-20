#include "stdafx.h"
#include "LeftBar.h"


LeftBar::LeftBar(GLuint programId, GLuint vao, ObjectLoader* objectLoader)
{
	this->programId = programId;
	this->vao = vao;
	this->object = new ThreeDimensionalObject(this->programId, this->vao, "./resources/objects/cube.obj", NULL, objectLoader);
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
