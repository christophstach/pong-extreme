#pragma once
class ArenaBoundaryRight : public GameObject
{
public:
	ArenaBoundaryRight(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
};

