#pragma once
class LeftBar : public GameObject
{
private:
	float position = 0;
	float speed = 35;
	GLdouble timeDelta = 0;

	ArenaBoundaryTop* arenaBoundaryTop;
	ArenaBoundaryBottom* arenaBoundaryBottom;
public:
	LeftBar(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();
	LeftBar* setPosition(float position);
	LeftBar* moveUp();
	LeftBar* moveDown();

	LeftBar* setArenaBoundaryTop(ArenaBoundaryTop* arenaBoundaryTop);
	LeftBar* setArenaBoundaryBottom(ArenaBoundaryBottom* arenaBoundaryBottom);
	LeftBar* setTimeDelta(GLdouble timeDelta);
	~LeftBar();
};

