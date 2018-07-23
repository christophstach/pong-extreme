#pragma once
class NumberRight : public GameObject
{
public:
	NumberRight(int number, ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
	~NumberRight();
};

