#pragma once
class RightBar: public ThreeDimensional
{
private:
	GLuint programId;
	GLuint vao;
	ThreeDimensionalObject* object;
	float position = 0;
public:
	RightBar(GLuint programId, GLuint vao, ObjectLoader* objectLoader);
	glm::mat4 transform(glm::mat4 model);
	void setPosition(float position);
	void draw();
};

