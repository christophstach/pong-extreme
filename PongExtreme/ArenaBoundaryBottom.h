#pragma once
class ArenaBoundaryBottom : public GameObject
{
public:
	ArenaBoundaryBottom(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
	~ArenaBoundaryBottom();
};

