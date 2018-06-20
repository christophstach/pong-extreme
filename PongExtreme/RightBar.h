#pragma once
class RightBar: public ThreeDimensional
{
private:
	ThreeDimensionalObject* object;
	float position = 0;
public:
	RightBar(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void setPosition(float position);
	void draw();
};

