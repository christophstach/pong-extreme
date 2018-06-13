#pragma once
class Ball: public ThreeDimensional
{
private:
	GLuint vao;
	Sphere * sphere;
public:
	Ball(GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

