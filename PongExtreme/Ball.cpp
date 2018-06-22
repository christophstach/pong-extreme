#include "stdafx.h"
#include "Ball.h"

Ball::Ball(ObjectLoader* objectLoader, GLuint vao)
{
	this->speed = 0.01;
	//							y    z    x
	this->position = glm::vec3(0.0, 0.0, 0.0);
	this->direction = glm::vec3(this->speed, 0.0, this->speed);
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/ball2.obj");
}

void Ball::checkCollisions()
{
	const int x = 2;
	const int y = 0;
	const int z = 1;
	

	


	// Check collision with left bar
	if ((this->leftBar->getBoundingBox()->min.z - this->getBoundingBox()->max.z) <= 0) {
		this->direction[x] = -this->speed;
	}

	printf("%f \n", this->rightBar->getBoundingBox()->max.z + this->getBoundingBox()->min.z);
	// Check collision with right bar
	if ((this->rightBar->getBoundingBox()->min.z + this->getBoundingBox()->min.z) <= 0) {
		this->direction[x] = this->speed;
	}

	if (this->boundingBox->max.x <= 10.0) {
		this->direction[y] = -this->speed;
	}

	if (this->boundingBox->max.x >= 10.0) {
		this->direction[y] = this->speed;
	}

	this->position += this->direction;
}

glm::mat4 Ball::transform(glm::mat4 model)
{
	glm::mat4 translate = glm::translate(glm::mat4(1.0), this->position);
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0), this->rotation, glm::vec3(1.0, 1.0, 1.0));
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(0.75, 0.75, 0.75));

	this->boundingBox->min = this->object->boundingBox->min * scale + glm::vec4(this->position.x, this->position.y, this->position.z, 0.0);
	this->boundingBox->max = this->object->boundingBox->max * scale + glm::vec4(this->position.x, this->position.y, this->position.z, 0.0);

	this->rotation += 0.01;
	this->checkCollisions();

	return model * translate * rotate * scale;
}

void Ball::draw()
{
	this->object->draw();
}

Ball * Ball::setLeftBar(LeftBar * leftBar)
{
	this->leftBar = leftBar;
	return this;
}

Ball * Ball::setRightBar(RightBar * rightBar)
{
	this->rightBar = rightBar;
	return this;
}


