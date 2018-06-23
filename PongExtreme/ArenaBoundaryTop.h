#pragma once
class ArenaBoundaryTop : public GameObject
{
public:
	ArenaBoundaryTop(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

