#include "stdafx.h"
#include "LeftBar.h"


LeftBar::LeftBar(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
}

glm::mat4 LeftBar::transform(glm::mat4 model) 
{
	glm::vec3 translateValue = glm::vec3(this->position, 0.0f, 16.0f);
	glm::vec3 scaleValue = glm::vec3(4.0f, 0.8f, 0.2f);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), translateValue);
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);
	
	this->transformBoundingBox(translateValue, scaleValue);
	return model * translate * scale;
}

void LeftBar::setPosition(float position)
{
	this->position = position;
}

void LeftBar::draw()
{
	this->object->draw();
}
