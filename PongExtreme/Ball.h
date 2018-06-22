#pragma once
class Ball : public GameObject
{
private:
	ThreeDimensionalObject * object;
	float rotation = 0;
	glm::vec3 position;
	glm::vec3 direction;

	float speed;

	LeftBar* leftBar;
	RightBar* rightBar;
public:
	Ball(ObjectLoader* objectLoader, GLuint vao);
	void checkCollisions();
	glm::mat4 transform(glm::mat4 model);
	void draw();
	Ball* setLeftBar(LeftBar* leftBar);
	Ball* setRightBar(RightBar* rightBar);
};

