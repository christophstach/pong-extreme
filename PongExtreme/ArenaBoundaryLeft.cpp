#include "stdafx.h"
#include "ArenaBoundaryLeft.h"

ArenaBoundaryLeft::ArenaBoundaryLeft(ObjectLoader * objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
}

glm::mat4 ArenaBoundaryLeft::transform(glm::mat4 model)
{
	glm::vec3 translateValue = glm::vec3(0.0, 0.0, 20.0);
	glm::vec3 scaleValue = glm::vec3(16.0, 1.0, 0.1);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), translateValue);
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);

	this->transformBoundingBox(translateValue, scaleValue);
	return model * translate * scale;
}

void ArenaBoundaryLeft::draw()
{
	this->object->draw();
}
