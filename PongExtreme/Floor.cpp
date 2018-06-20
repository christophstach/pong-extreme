#include "stdafx.h"
#include "Floor.h"


Floor::Floor(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/cube.obj");
}

glm::mat4 Floor::transform(glm::mat4 model)
{
	model = glm::translate(model, glm::vec3(0.0, -5.0, 0.0));
	model = glm::scale(model, glm::vec3(1000.0, 0.5, 100.0));
	return model;
}

void Floor::draw()
{
	this->object->draw();
}