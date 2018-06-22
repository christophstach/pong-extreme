#include "stdafx.h"
#include "GameObject.h"

glm::mat4 GameObject::transform(glm::mat4 model)
{
	return model;
}

BoundingBox * GameObject::getBoundingBox()
{
	return this->boundingBox;
}

void GameObject::draw()
{
}
