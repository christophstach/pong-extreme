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

LeftBar* LeftBar::setPosition(float position)
{
	this->position = position;
	return this;
}

GameObject* LeftBar::draw()
{
	this->object->draw();
	return this;
}

LeftBar* LeftBar::moveUp()
{
	if (this->getBoundingBox()->min.x >= this->arenaBoundaryTop->getBoundingBox()->max.x) {
		this->position -= this->speed * this->timeDelta;
	}

	return this;
}

LeftBar* LeftBar::moveDown()
{
	if (this->getBoundingBox()->max.x <= this->arenaBoundaryBottom->getBoundingBox()->min.x) {
		this->position += this->speed * this->timeDelta;
	}

	return this;
}

LeftBar * LeftBar::setArenaBoundaryTop(ArenaBoundaryTop * arenaBoundaryTop)
{
	this->arenaBoundaryTop = arenaBoundaryTop;
	return this;
}

LeftBar * LeftBar::setArenaBoundaryBottom(ArenaBoundaryBottom * arenaBoundaryBottom)
{
	this->arenaBoundaryBottom = arenaBoundaryBottom;
	return this;
}

LeftBar * LeftBar::setTimeDelta(GLdouble timeDelta)
{
	this->timeDelta = timeDelta;
	return this;
}
