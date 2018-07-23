#include "stdafx.h"
#include "NumberLeft.h"

NumberLeft::NumberLeft(int number, ObjectLoader * objectLoader, GLuint vao)
{
	switch (number) {
	case 0:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/zero.obj");
		break;
	case 1:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/one.obj");
		break;
	case 2:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/two.obj");
		break;
	case 3:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/three.obj");
		break;
	case 4:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/four.obj");
		break;
	case 5:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/five.obj");
		break;
	case 6:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/six.obj");
		break;
	case 7:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/seven.obj");
		break;
	case 8:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/eight.obj");
		break;
	case 9:
		this->object = new ThreeDimensionalObject(objectLoader, vao, "./resources/objects/nine.obj");
		break;
	}
}

glm::mat4 NumberLeft::transform(glm::mat4 model)
{
	glm::vec3 translateValue = glm::vec3(-5.0, 10.0, 20.0);
	glm::vec3 scaleValue = glm::vec3(6.0, 6.0, 6.0);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), translateValue);
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0), 1.5708f, glm::vec3(0.0, 1.0, 0.0)) *  glm::rotate(glm::mat4(1.0), 1.0f, glm::vec3(1.0, 0.0, 0.0));
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaleValue);

	this->transformBoundingBox(translateValue, scaleValue);
	return model * translate * rotate * scale;
}

GameObject * NumberLeft::draw()
{
	this->object->draw();
	return this;
}

NumberLeft::~NumberLeft()
{
	delete this->object;
}
