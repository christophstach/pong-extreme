#pragma once
class Ball: public ThreeDimensional
{
private:
	ThreeDimensionalObject* object;
	float rotation = 0;
public:
	Ball(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

