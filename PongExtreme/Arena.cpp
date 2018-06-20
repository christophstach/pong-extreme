#include "stdafx.h"
#include "Arena.h"


Arena::Arena(ObjectLoader* objectLoader, GLuint vao)
{
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/arena.obj");
}

glm::mat4 Arena::transform(glm::mat4 model)
{
	model = glm::scale(model, glm::vec3(glm::vec3(5.85, 15.0, 5.85)));
	return model;
}

void Arena::draw()
{
	this->object->draw();
}