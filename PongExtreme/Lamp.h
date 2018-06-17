#pragma once
class Lamp: public ThreeDimensional
{
private: 
	GLuint vao;
	Cube * cube;
public:
	Lamp(GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

