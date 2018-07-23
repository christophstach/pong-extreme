#include "stdafx.h"
#include "GameObject.h"

glm::mat4 GameObject::transform(glm::mat4 model)
{
	return model;
}

GameObject* GameObject::transformBoundingBox(glm::vec3 translateValue, glm::vec3 scaleValue)
{
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);

	this->boundingBox->min = this->object->boundingBox->min * scale + glm::vec4(translateValue.x, translateValue.y, translateValue.z, 0.0);
	this->boundingBox->max = this->object->boundingBox->max * scale + glm::vec4(translateValue.x, translateValue.y, translateValue.z, 0.0);

	return this;
}

BoundingBox * GameObject::getBoundingBox()
{
	return this->boundingBox;
}

GameObject* GameObject::draw()
{
	return this;
}

GameObject::~GameObject()
{
	delete this->object;
	delete this->boundingBox;
}
