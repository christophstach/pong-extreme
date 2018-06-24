#pragma once
class ArenaBoundaryLeft : public GameObject
{
public:
	ArenaBoundaryLeft(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
};

