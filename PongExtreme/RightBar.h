#pragma once
class RightBar: public ThreeDimensional
{
private:
	GLuint vao;
	Cube * cube;
	float position = 0;
public:
	RightBar(GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void setPosition(float position);
	void draw();
};

