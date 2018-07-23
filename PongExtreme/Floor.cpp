#include "stdafx.h"
#include "Floor.h"


Floor::Floor(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
}

glm::mat4 Floor::transform(glm::mat4 model)
{
	glm::vec3 translateValue = glm::vec3(0.0, -5.0, 0.0);
	glm::vec3 scaleValue = glm::vec3(1000.0, 0.5, 10000.0);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), translateValue);
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);

	this->transformBoundingBox(translateValue, scaleValue);
	return model * translate * scale;
}

GameObject* Floor::draw()
{
	this->object->draw();
	return this;
}

Floor::~Floor()
{
	delete this->object;
}
