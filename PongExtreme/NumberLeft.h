#pragma once
class NumberLeft : public GameObject
{
public:
	NumberLeft(int number, ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
	~NumberLeft();
};

