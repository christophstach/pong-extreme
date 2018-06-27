#include "stdafx.h"
#include "RightBar.h"


RightBar::RightBar(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
}

glm::mat4 RightBar::transform(glm::mat4 model)
{
	glm::vec3 translateValue = glm::vec3(this->position, 0.0f, -19.0f);
	glm::vec3 scaleValue = glm::vec3(4.0f, 0.8f, 0.2f);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), translateValue);
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);

	this->transformBoundingBox(translateValue, scaleValue);
	return model * translate * scale;
}

RightBar* RightBar::setPosition(float position)
{
	this->position = position;
	return this;
}

GameObject* RightBar::draw()
{
	this->object->draw();
	return this;
}

RightBar* RightBar::moveUp()
{
	if (this->getBoundingBox()->min.x >= this->arenaBoundaryTop->getBoundingBox()->max.x) {
		this->position -= this->speed * this->timeDelta;
	}

	return this;
}

RightBar* RightBar::moveDown()
{
	if (this->getBoundingBox()->max.x <= this->arenaBoundaryBottom->getBoundingBox()->min.x) {
		this->position += this->speed * this->timeDelta;
	}

	return this;
}

RightBar * RightBar::setArenaBoundaryTop(ArenaBoundaryTop * arenaBoundaryTop)
{
	this->arenaBoundaryTop = arenaBoundaryTop;
	return this;
}

RightBar * RightBar::setArenaBoundaryBottom(ArenaBoundaryBottom * arenaBoundaryBottom)
{
	this->arenaBoundaryBottom = arenaBoundaryBottom;
	return this;
}

RightBar* RightBar::setTimeDelta(GLdouble timeDelta)
{
	this->timeDelta = timeDelta;
	return this;
}
