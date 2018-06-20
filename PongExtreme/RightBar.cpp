#include "stdafx.h"
#include "RightBar.h"


RightBar::RightBar(GLuint programId, GLuint vao, ObjectLoader* objectLoader)
{
	this->programId = programId;
	this->vao = vao;
	this->object = new ThreeDimensionalObject(this->programId, this->vao, "./resources/objects/cube.obj", NULL, objectLoader);
}

glm::mat4 RightBar::transform(glm::mat4 model)
{
	model = glm::translate(model, glm::vec3(this->position, 0.0f, -16.0f));
	model = glm::scale(model, glm::vec3(4.0f, 0.8f, 0.2f));
	return model;
}

void RightBar::setPosition(float position)
{
	this->position = position;
}

void RightBar::draw()
{
	this->object->draw();
}
