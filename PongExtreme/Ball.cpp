#include "stdafx.h"
#include "Ball.h"

Ball::Ball(ObjectLoader* objectLoader, GLuint vao)
{
	//							y    z    x
	this->position = glm::vec3(0.0, 0.0, 0.0);
	this->direction = glm::vec3(1.0, 0.0, 1.0);
	this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/ball.obj");
	this->ballCollisionSound = new WaveSound("./resources/audios/tennisserve.wav");
}

void Ball::checkCollisions()
{
	const int x = 2;
	const int y = 0;
	const int z = 1;
	double random = ((double)rand() / (RAND_MAX));

	if (this->hasCollisionWithLeftBar()) this->direction[x] = -random;
	if (this->hasCollisionWithRightBar()) this->direction[x] = random;

	if (this->hasCollisionWithArenaBoundaryLeft()) this->direction[x] = -1.0;
	if (this->hasCollisionWithArenaBoundaryRight()) this->direction[x] = 1.0;
	if (this->hasCollisionWithArenaBoundaryTop()) this->direction[y] = -this->direction[y];
	if (this->hasCollisionWithArenaBoundaryBottom()) this->direction[y] = -this->direction[y];

	this->position += glm::vec3(
		this->direction.x * this->speed * this->timeDelta,
		this->direction.y * this->speed * this->timeDelta,
		this->direction.z * this->speed * this->timeDelta
	);
}

glm::mat4 Ball::transform(glm::mat4 model)
{
	if (this->speed != 0.0) {
		this->rotation += 5.0 * this->timeDelta;
	}

	glm::vec3 translateValue = this->position;
	glm::vec3 rotateValue = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 scaleValue = glm::vec3(0.75, 0.75, 0.75);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), translateValue);
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0), this->rotation, rotateValue);
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);

	this->transformBoundingBox(translateValue, scaleValue);
	this->checkCollisions();
	return model * translate * rotate * scale;
}

GameObject* Ball::draw()
{
	this->object->draw();
	return this;
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

Ball * Ball::setArenaBoundaryTop(ArenaBoundaryTop* arenaBoundaryTop)
{
	this->arenaBoundaryTop = arenaBoundaryTop;
	return this;
}

Ball * Ball::setArenaBoundaryRight(ArenaBoundaryRight* arenaBoundaryRight)
{
	this->arenaBoundaryRight = arenaBoundaryRight;
	return this;
}

Ball * Ball::setArenaBoundaryBottom(ArenaBoundaryBottom* arenaBoundaryBottom)
{
	this->arenaBoundaryBottom = arenaBoundaryBottom;
	return this;
}

Ball * Ball::setArenaBoundaryLeft(ArenaBoundaryLeft* arenaBoundaryLeft)
{
	this->arenaBoundaryLeft = arenaBoundaryLeft;
	return this;
}

Ball * Ball::setTimeDelta(GLdouble timeDelta)
{
	this->timeDelta = timeDelta;
	return this;
}

Ball * Ball::startRolling(float speed)
{
	this->speed = speed;
	return this;
}

Ball * Ball::stopRolling()
{
	this->speed = 0.0;
	return this;
}

bool Ball::isRolling()
{
	return this->speed != 0.0;
}

bool Ball::hasCollisionWithLeftBar()
{
	if (this->leftBar->getBoundingBox()->min.z - this->getBoundingBox()->max.z <= 0) {
		if ((this->getBoundingBox()->min.x >= this->leftBar->getBoundingBox()->min.x && this->getBoundingBox()->min.x <= this->leftBar->getBoundingBox()->max.x) || (this->getBoundingBox()->max.x >= this->leftBar->getBoundingBox()->min.x && this->getBoundingBox()->max.x <= this->leftBar->getBoundingBox()->max.x)) {
			this->ballCollisionSound->play();
			return true;
		}
	}

	return false;
}

bool Ball::hasCollisionWithRightBar()
{
	if (this->rightBar->getBoundingBox()->max.z - this->getBoundingBox()->min.z >= 0) {
		if ((this->getBoundingBox()->min.x >= this->rightBar->getBoundingBox()->min.x && this->getBoundingBox()->min.x <= this->rightBar->getBoundingBox()->max.x) || (this->getBoundingBox()->max.x >= this->rightBar->getBoundingBox()->min.x && this->getBoundingBox()->max.x <= this->rightBar->getBoundingBox()->max.x)) {
			this->ballCollisionSound->play();
			return true;
		}
	}

	return false;
}

bool Ball::hasCollisionWithArenaBoundaryTop()
{
	return this->arenaBoundaryTop->getBoundingBox()->max.x - this->getBoundingBox()->min.x >= 0;
}

bool Ball::hasCollisionWithArenaBoundaryRight()
{
	if (this->arenaBoundaryRight->getBoundingBox()->max.z - this->getBoundingBox()->min.z >= 0) {
		this->speed = 0.0;
		this->position.x = 0.0;
		this->position.z = 0.0;

		return true;
	}

	return false;
}

bool Ball::hasCollisionWithArenaBoundaryBottom()
{
	return this->arenaBoundaryBottom->getBoundingBox()->min.x - this->getBoundingBox()->max.x <= 0;
}

bool Ball::hasCollisionWithArenaBoundaryLeft()
{
	if (this->arenaBoundaryLeft->getBoundingBox()->min.z - this->getBoundingBox()->max.z <= 0) {
		this->speed = 0.0;
		this->position.x = 0.0;
		this->position.z = 0.0;

		return true;
	}

	return false;
}


