#pragma once
class Floor : public GameObject
{
public:
	Floor(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
	~Floor();
};

