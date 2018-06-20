#include "stdafx.h"
#include "Arena.h"


Arena::Arena(GLuint programId, GLuint vao, ObjectLoader* objectLoader)
{
	this->programId = programId;
	this->vao = vao;
	this->object = new ThreeDimensionalObject(this->programId, this->vao, "./resources/objects/arena.obj", "./resources/textures/mandrill.bmp", objectLoader);
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