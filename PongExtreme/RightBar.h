#pragma once
class RightBar: public GameObject
{
private:
	float position = 0;
	float speed = 35;
	GLdouble timeDelta = 0;

	ArenaBoundaryTop* arenaBoundaryTop;
	ArenaBoundaryBottom* arenaBoundaryBottom;
public:
	RightBar(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
	RightBar* setPosition(float position);
	RightBar* moveUp();
	RightBar* moveDown();

	RightBar* setArenaBoundaryTop(ArenaBoundaryTop* arenaBoundaryTop);
	RightBar* setArenaBoundaryBottom(ArenaBoundaryBottom* arenaBoundaryBottom);
	RightBar* setTimeDelta(GLdouble timeDelta);
};

