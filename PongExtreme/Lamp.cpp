#include "stdafx.h"
#include "Lamp.h"

Lamp::Lamp(GLuint vao)
{
	this->vao = vao;
	this->cube = new Cube(this->vao);
}

glm::mat4 Lamp::transform(glm::mat4 model)
{
	model = glm::translate(model, glm::vec3(-8.0f, 10.0f, 8.0f));
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
	return model;
}

void Lamp::draw()
{
	this->cube->draw();
}
