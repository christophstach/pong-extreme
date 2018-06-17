#include "stdafx.h"
#include "Arena.h"


Arena::Arena(GLuint vao, ObjectLoader* objectLoader, TextureLoader* textureLoader)
{
	this->object = new ThreeDimensionalObject(this->vao, "./resources/objects/arena.obj", objectLoader, textureLoader);
}

glm::mat4 Arena::transform(glm::mat4 model)
{
	model = glm::scale(model, glm::vec3(glm::vec3(5.85, 5.85, 5.85)));
	return model;
}

void Arena::draw()
{
	this->object->draw();
}