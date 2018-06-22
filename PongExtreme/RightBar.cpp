#include "stdafx.h"
#include "RightBar.h"


RightBar::RightBar(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
}

glm::mat4 RightBar::transform(glm::mat4 model)
{
	glm::mat4 translate = glm::translate(glm::mat4(1.0), glm::vec3(this->position, 0.0f, -16.0f));
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(4.0f, 0.8f, 0.2f));

	this->boundingBox->min = this->object->boundingBox->min * scale + glm::vec4(this->position, 0.0f, 16.0f, 0.0);
	this->boundingBox->max = this->object->boundingBox->max * scale + glm::vec4(this->position, 0.0f, 16.0f, 0.0);

	return model * translate * scale;
}

void RightBar::setPosition(float position)
{
	this->position = position;
}

void RightBar::draw()
{
	this->object->draw();
}
