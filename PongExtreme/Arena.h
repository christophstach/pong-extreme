#pragma once
class Arena : public ThreeDimensional
{
private:
	GLuint programId;
	GLuint vao;
	ThreeDimensionalObject* object;
public:
	Arena(GLuint programId, GLuint vao, ObjectLoader* objectLoader);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

