#pragma once
class Ball : public GameObject
{
private:
	float rotation = 0;
	float speed = 12.0;
	glm::vec3 position;
	glm::vec3 direction;
	GLdouble timeDelta = 0;

	LeftBar* leftBar;
	RightBar* rightBar;
	ArenaBoundaryTop* arenaBoundaryTop;
	ArenaBoundaryRight* arenaBoundaryRight;
	ArenaBoundaryBottom* arenaBoundaryBottom;
	ArenaBoundaryLeft* arenaBoundaryLeft;

	WaveSound* ballCollisionSound;
public:
	Ball(ObjectLoader* objectLoader, GLuint vao);
	void checkCollisions();
	glm::mat4 transform(glm::mat4 model);
	GameObject* draw();

	Ball* setLeftBar(LeftBar* leftBar);
	Ball* setRightBar(RightBar* rightBar);
	Ball* setArenaBoundaryTop(ArenaBoundaryTop* arenaBoundaryTop);
	Ball* setArenaBoundaryRight(ArenaBoundaryRight* arenaBoundaryRight);
	Ball* setArenaBoundaryBottom(ArenaBoundaryBottom* arenaBoundaryBottom);
	Ball* setArenaBoundaryLeft(ArenaBoundaryLeft* arenaBoundaryLeft);
	Ball* setTimeDelta(GLdouble timeDelta);

	bool hasCollisionWithLeftBar();
	bool hasCollisionWithRightBar();
	bool hasCollisionWithArenaBoundaryTop();
	bool hasCollisionWithArenaBoundaryRight();
	bool hasCollisionWithArenaBoundaryBottom();
	bool hasCollisionWithArenaBoundaryLeft();
};

